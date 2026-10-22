#pragma once
#include "SensorType.h"
#include <string>
#include <vector>

class Sensor {
public:
	Sensor() = default;
	Sensor(uint16_t id, SensorType type, const std::string &timestamp,bool status);
private:
	uint16_t m_id;
	SensorType m_type;
	std::string m_timestamp;
	bool m_status;
};