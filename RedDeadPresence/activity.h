#pragma once
#include "pch.h"

namespace presencemod::activity
{
	enum class ActivityType
	{
		ACTIVITY_NONE,
		ACTIVITY_FISHING,
		ACTIVITY_BLACKJACK,
		ACTIVITY_POKER,
		ACTIVITY_DOMINOES,
		ACTIVITY_FILLET,
		MAX_ACTIVITIES
	};

	struct ActivityDefinition
	{
		uint32_t scriptHash;
		std::string title;
		std::string activityImageKey;
	};

	ActivityType getCurrentActivity();
	std::string getActivityTitle(ActivityType);
	std::string getActivityImageKey(ActivityType);
}