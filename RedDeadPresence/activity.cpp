#include "pch.h"
#include "activity.h"

namespace presencemod::activity
{
	const ActivityDefinition activityDefinitions[] = {
		// script hash - activity name - activity small icon key
		{ 0, "Free-roaming" },
		{ joaat::generate("fishing_core"), "Fishing", "activity_fishing" },
		{ joaat::generate("bjack_sp"), "Playing Blackjack", "activity_blackjack" },
		{ joaat::generate("poker_sp"), "Playing Poker", "activity_poker" },
		{ joaat::generate("dominoes_sp"), "Playing Dominoes", "activity_dominoes" },
		{ joaat::generate("fillet_sp"), "Playing Five Finger Fillet", "activity_five_finger_fillet" }
	};

	ActivityType getCurrentActivity()
	{
		for (int i = 1; i < static_cast<int>(ActivityType::MAX_ACTIVITIES); i++)
		{
			if (SCRIPTS::_GET_NUMBER_OF_REFERENCES_OF_SCRIPT_WITH_NAME_HASH(activityDefinitions[i].scriptHash) > 0)
			{
				return static_cast<ActivityType>(i);
			}
		}

		return ActivityType::ACTIVITY_NONE;
	}

	std::string getActivityTitle(ActivityType activityType)
	{
		if (activityType < ActivityType::ACTIVITY_NONE || activityType >= ActivityType::MAX_ACTIVITIES)
		{
			return activityDefinitions[static_cast<int>(ActivityType::ACTIVITY_NONE)].title;
		}

		return activityDefinitions[static_cast<int>(activityType)].title;
	}

	std::string getActivityImageKey(ActivityType activityType)
	{
		if (activityType < ActivityType::ACTIVITY_NONE || activityType >= ActivityType::MAX_ACTIVITIES)
		{
			return activityDefinitions[static_cast<int>(ActivityType::ACTIVITY_NONE)].activityImageKey;
		}

		return activityDefinitions[static_cast<int>(activityType)].activityImageKey;
	}
}