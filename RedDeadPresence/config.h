#pragma once
#include "pch.h"

namespace presencemod::config
{
	constexpr const char* DEFAULT_CONFIG_FILE     = "RedDeadPresence.config.json";
	constexpr const char* DEFAULT_DISCORD_APPID   = "819521582966898709";
	constexpr const int   DEFAULT_UPDATE_INTERVAL = 15000;

	struct PresenceModConfig
	{
		std::string discordAppId = DEFAULT_DISCORD_APPID;
		int updateInterval = DEFAULT_UPDATE_INTERVAL;
		bool showHonorIcon = true;
		bool showActivity = true;
		bool showMissionName = true;
		bool showElapsedTime = true;
	};

	bool parse(const std::string&, PresenceModConfig&);
}