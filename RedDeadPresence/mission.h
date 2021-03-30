#pragma once
#include "pch.h"

namespace presencemod::mission
{
	struct MissionDefinition
	{
		uint32_t scriptHash;
		std::string name;
	};

	std::string getActiveMissionName();
}