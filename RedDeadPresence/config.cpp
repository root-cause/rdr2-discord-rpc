#include "pch.h"
#include "config.h"

namespace presencemod::config
{
	bool parse(const std::string& file, PresenceModConfig& target)
	{
		std::ifstream configFile(file);
		if (!configFile.good())
		{
			return false;
		}

		nlohmann::json config = nlohmann::json::parse(configFile);
		target.discordAppId = config.value("discordAppId", DEFAULT_DISCORD_APPID);
		target.updateInterval = config.value("updateInterval", DEFAULT_UPDATE_INTERVAL);
		target.showHonorIcon = config.value("displayHonor", true);
		target.showActivity = config.value("displayActivity", true);
		target.showMissionName = config.value("displayMissionName", true);
		target.showElapsedTime = config.value("displayElapsedTime", true);
		return true;
	}
}