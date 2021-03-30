#include "pch.h"
#include "script.h"
#include "config.h"
#include "location.h"
#include "honor.h"
#include "activity.h"
#include "mission.h"

namespace presencemod
{
	const time_t g_startedAt = time(nullptr);
	config::PresenceModConfig g_config;

	bool g_doPresenceUpdates;
	std::string g_lastPresenceState;
	std::string g_lastPresenceDetails;

	// Discord callbacks
	void onDiscordReady(const DiscordUser* user)
	{
		g_doPresenceUpdates = true;
		spdlog::info("Connected");
	}

	void onDiscordDisconnect(int errorCode, const char* errorMessage)
	{
		g_doPresenceUpdates = false;
		spdlog::info("Disconnected (code: {} - {})", errorCode, errorMessage);
	}

	void onDiscordError(int errorCode, const char* errorMessage)
	{
		g_doPresenceUpdates = false;
		spdlog::error("{} - {}", errorCode, errorMessage);
	}

	// Script functions
	void onScriptInit()
	{
		// Set up logger
		spdlog::set_default_logger(spdlog::basic_logger_mt("logger", "RedDeadPresence.log", true));
		spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");
		spdlog::flush_on(spdlog::level::info);
		spdlog::info("RedDeadPresence started");

		// Read config
		if (!config::parse(config::DEFAULT_CONFIG_FILE, g_config))
		{
			spdlog::error("{} not found", config::DEFAULT_CONFIG_FILE);
			return;
		}

		spdlog::info("Discord application ID: {}", g_config.discordAppId);

		// Request "MAP" text block (or we can't get location names)
		HUD::TEXT_BLOCK_REQUEST("MAP");

		// Set up event handlers
		DiscordEventHandlers handlers;
		memset(&handlers, 0, sizeof(handlers));

		handlers.ready = onDiscordReady;
		handlers.disconnected = onDiscordDisconnect;
		handlers.errored = onDiscordError;

		spdlog::info("Connecting...");
		
		// Init rich presence
		Discord_Initialize(g_config.discordAppId.c_str(), &handlers, 1, RDR2_STEAM_APPID);

		// Update loop
		doScriptUpdates();
	}

	void doScriptUpdates()
	{
		ULONGLONG nextUpdate = 0;

		while (true)
		{
			Discord_UpdateConnection();
			Discord_RunCallbacks();

			if (g_doPresenceUpdates && nextUpdate < GetTickCount64() && HUD::TEXT_BLOCK_IS_LOADED("MAP"))
			{
				const Vector3 curPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false, false);
				activity::ActivityType curActivityType = activity::ActivityType::ACTIVITY_NONE;
				std::string newState;
				std::string newDetails;

				// Update location/state (current order is TEXT_WRITTEN > TEXT_PRINTED > DISTRICT)
				const std::string writtenZone = location::getTextWrittenName(curPosition);
				const std::string printedZone = location::getTextPrintedName(curPosition);

				if (!writtenZone.empty())
				{
					newState = writtenZone;
				}
				else if (writtenZone.empty() && !printedZone.empty())
				{
					newState = printedZone;
				}
				else if (writtenZone.empty() && printedZone.empty())
				{
					newState = location::getDistrictName(curPosition);
				}

				// Update activity/details
				if (g_config.showActivity)
				{
					if (MISC::GET_MISSION_FLAG())
					{
						newDetails = g_config.showMissionName ? fmt::format("In Mission: {}", mission::getActiveMissionName()) : "In a mission";
					}
					else
					{
						curActivityType = activity::getCurrentActivity();
						newDetails = activity::getActivityTitle(curActivityType);
					}
				}

				// Update rich presence
				if (newState != g_lastPresenceState || newDetails != g_lastPresenceDetails)
				{
					std::string smallImageKey;

					DiscordRichPresence presence;
					memset(&presence, 0, sizeof(presence));

					// Honor icon (if enabled)
					if (g_config.showHonorIcon)
					{
						const int currentHonor = honor::getCurrentHonor();
						smallImageKey = fmt::format("honor_{}", honor::getHonorLevel(currentHonor));
					}

					// Activity icon (if enabled and doing an activity)
					if (g_config.showActivity && curActivityType != activity::ActivityType::ACTIVITY_NONE)
					{
						smallImageKey = activity::getActivityImageKey(curActivityType);
					}

					if (g_config.showElapsedTime)
					{
						presence.startTimestamp = g_startedAt;
					}

					presence.largeImageKey = "rdr2_main";
					presence.smallImageKey = smallImageKey.c_str();
					presence.state = newState.c_str();
					presence.details = newDetails.c_str();
					Discord_UpdatePresence(&presence);

					// Update globals
					g_lastPresenceState = newState;
					g_lastPresenceDetails = newDetails;
				}

				nextUpdate = GetTickCount64() + g_config.updateInterval;
			}

			WAIT(1000);
		}
	}

	void onScriptExit()
	{
		g_doPresenceUpdates = false;
		Discord_Shutdown();

		spdlog::info("RedDeadPresence stopped");
		spdlog::shutdown();
	}
}