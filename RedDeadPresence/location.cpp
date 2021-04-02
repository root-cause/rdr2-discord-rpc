#include "pch.h"
#include "location.h"

namespace presencemod::location
{
	std::string getDistrictName(const Vector3& position)
	{
		// District names source: https://github.com/femga/rdr3_discoveries/tree/master/zones
		// Labels are from map.yldb
		switch (ZONE::_GET_MAP_ZONE_AT_COORDS(position.x, position.y, position.z, static_cast<int>(ZoneType::DISTRICT)))
		{
			case joaat::generate("BayouNwa"):
				return HUD::_GET_LABEL_TEXT("P_2_BAYOU_NWA");

			case joaat::generate("bigvalley"):
				return HUD::_GET_LABEL_TEXT("P_2_BIG_VALLEY");

			case joaat::generate("BluewaterMarsh"):
				return HUD::_GET_LABEL_TEXT("P_2_BLUEWATER_MARSH");

			case joaat::generate("ChollaSprings"):
				return HUD::_GET_LABEL_TEXT("P_2_CHOLLA_SPRINGS");

			case joaat::generate("Cumberland"):
				return HUD::_GET_LABEL_TEXT("P_2_CUMBERLAND_FOREST");

			case joaat::generate("DiezCoronas"):
				return HUD::_GET_LABEL_TEXT("P_2_DIEZ_CORONAS");

			case joaat::generate("GaptoothRidge"):
				return HUD::_GET_LABEL_TEXT("P_2_GAPTOOTH_RIDGE");

			case joaat::generate("greatPlains"):
				return HUD::_GET_LABEL_TEXT("P_2_GREAT_PLAINS");

			case joaat::generate("GrizzliesEast"):
				return HUD::_GET_LABEL_TEXT("P_2_GRIZZLIES_EAST");

			case joaat::generate("GrizzliesWest"):
				return HUD::_GET_LABEL_TEXT("P_2_GRIZZLIES_WEST");

			case joaat::generate("GuarmaD"):
				return HUD::_GET_LABEL_TEXT("P_1_GUARMA");

			case joaat::generate("Heartlands"):
				return HUD::_GET_LABEL_TEXT("P_2_THE_HEARTLANDS");

			case joaat::generate("HennigansStead"):
				return HUD::_GET_LABEL_TEXT("P_2_HENNIGANS_STEAD");

			case joaat::generate("Perdido"):
				return HUD::_GET_LABEL_TEXT("P_2_PERDIDO");

			case joaat::generate("PuntaOrgullo"):
				return HUD::_GET_LABEL_TEXT("P_2_PUNTA_ORGULLO");

			case joaat::generate("RioBravo"):
				return HUD::_GET_LABEL_TEXT("P_2_RIO_BRAVO");

			case joaat::generate("roanoke"):
				return HUD::_GET_LABEL_TEXT("P_2_ROANOKE_RIDGE");

			case joaat::generate("scarlettMeadows"):
				return HUD::_GET_LABEL_TEXT("P_2_SCARLETT_MEADOWS");

			case joaat::generate("TallTrees"):
				return HUD::_GET_LABEL_TEXT("P_2_TALL_TREES");

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