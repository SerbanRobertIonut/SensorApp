#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace sensors
{
	enum class SensorType : std::uint8_t
	{
		TEMP,
		ACCM,
	};

	SensorType toSensorType(std::string_view str);

	std::string to_string(SensorType type);
}
