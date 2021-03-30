#include "pch.h"
#include "location.h"

namespace presencemod::location
{
	std::string getDistrictName(const Vector3& position)
	{
		// District names source: https://github.com/femga/rdr3_discoveries/tree/master/zones
		// String hashes are from map.yldb
		switch (ZONE::_GET_MAP_ZONE_AT_COORDS(position.x, position.y, position.z, static_cast<int>(ZoneType::DISTRICT)))
		{
			case joaat::generate("BayouNwa"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x86778A95);

			case joaat::generate("bigvalley"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x171C4B1A);

			case joaat::generate("BluewaterMarsh"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x93334804);

			case joaat::generate("ChollaSprings"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x11391C65);

			case joaat::generate("Cumberland"):
				return HUD::GET_STRING_FROM_HASH_KEY(0xCA578D64);

			case joaat::generate("DiezCoronas"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x1C5F6063);

			case joaat::generate("GaptoothRidge"):
				return HUD::GET_STRING_FROM_HASH_KEY(0xD4024B27);

			case joaat::generate("greatPlains"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x2106539A);

			case joaat::generate("GrizzliesEast"):
				return HUD::GET_STRING_FROM_HASH_KEY(0xEF2B4071);

			case joaat::generate("GrizzliesWest"):
				return HUD::GET_STRING_FROM_HASH_KEY(0xA7038976);

			case joaat::generate("GuarmaD"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x27FC2128);

			case joaat::generate("Heartlands"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x033F6174);

			case joaat::generate("HennigansStead"):
				return HUD::GET_STRING_FROM_HASH_KEY(0xDCBBE18F);

			case joaat::generate("Perdido"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x1D6954B5);

			case joaat::generate("PuntaOrgullo"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x66A647D7);

			case joaat::generate("RioBravo"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x2F72C8B1);

			case joaat::generate("roanoke"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x2E4CEDDE);

			case joaat::generate("scarlettMeadows"):
				return HUD::GET_STRING_FROM_HASH_KEY(0x88F8D1D0);

			case joaat::generate("TallTrees"):
				return HUD::GET_STRING_FROM_HASH_KEY(0xE09C9EC2);

			default:
				return "Unknown Location";
		}
	}

	std::string getTextPrintedName(const Vector3& position)
	{
		Hash zoneHash = ZONE::_GET_MAP_ZONE_AT_COORDS(position.x, position.y, position.z, static_cast<int>(ZoneType::TEXT_PRINTED));
		return zoneHash == 0 ? "" : HUD::GET_STRING_FROM_HASH_KEY(zoneHash);
	}

	std::string getTextWrittenName(const Vector3& position)
	{
		Hash zoneHash = ZONE::_GET_MAP_ZONE_AT_COORDS(position.x, position.y, position.z, static_cast<int>(ZoneType::TEXT_WRITTEN));
		return zoneHash == 0 ? "" : HUD::GET_STRING_FROM_HASH_KEY(zoneHash);
	}
}