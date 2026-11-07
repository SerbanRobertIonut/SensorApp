#include "SensorType.h"

namespace sensors
{
	SensorType toSensorType(std::string_view str)
	{
		using enum SensorType;
		if (str == "TEMP")
		{
			return TEMP;
		}
		else if (str == "ACCM")
		{
			return ACCM;
		}
		else
		{
			throw std::exception{ "Incorrect string value to parse a SensorType" };
		}
	}

	std::string to_string(SensorType type)
	{
		using enum SensorType;
		switch (type)
		{
		case TEMP:
			return "TEMP";
		case ACCM:
			return "ACCM";
		default:
			throw std::exception{ "Undefined value for enum SensorType" };
		}
	}
}
