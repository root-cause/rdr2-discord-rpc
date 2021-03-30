#include "pch.h"
#include "honor.h"

namespace presencemod::honor
{
	int getCurrentHonor()
	{
		StatId statId;
		statId.BaseId = joaat::generate("honor_current");

		int result;
		STATS::STAT_ID_GET_INT(reinterpret_cast<Any*>(&statId), &result);
		return result;
	}

	// Copypasted from decompiled scripts
	int getHonorLevel(int honor)
	{
		if (honor <= -320) {
			return 0;
		}
		else if (honor <= -280) {
			return 1;
		}
		else if (honor <= -240) {
			return 2;
		}
		else if (honor <= -200) {
			return 3;
		}
		else if (honor <= -160) {
			return 4;
		}
		else if (honor <= -120) {
			return 5;
		}
		else if (honor <= -80) {
			return 6;
		}
		else if (honor < 0) {
			return 7;
		}
		else if (honor <= 40) {
			return 8;
		}
		else if (honor >= 320) {
			return 15;
		}
		else if (honor >= 280) {
			return 14;
		}
		else if (honor >= 240) {
			return 13;
		}
		else if (honor >= 200) {
			return 12;
		}
		else if (honor >= 160) {
			return 11;
		}
		else if (honor >= 120) {
			return 10;
		}
		else if (honor >= 80) {
			return 9;
		}

		return 8;
	}
}