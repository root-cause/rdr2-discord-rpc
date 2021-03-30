#pragma once
#include "pch.h"

namespace presencemod::location
{
	// Source: https://alloc8or.re/rdr3/nativedb/?n=0x43AD8FC02B429D33
	enum class ZoneType
	{
		STATE,
		TOWN,
		LAKE,
		RIVER,
		OIL_SPILL,
		SWAMP,
		OCEAN,
		CREEK,
		POND,
		GLACIER,
		DISTRICT,
		TEXT_PRINTED,
		TEXT_WRITTEN
	};

	std::string getDistrictName(const Vector3&);
	std::string getTextPrintedName(const Vector3&);
	std::string getTextWrittenName(const Vector3&);
}