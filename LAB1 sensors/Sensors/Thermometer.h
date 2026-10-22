#pragma once
#include "Sensor.h"
class Thermometer : public Sensor 
{
public:
	Thermometer(uint16_t id, SensorType type, const std::string& timestamp, bool status, float temperature);
private:
	static const float kMinTemperature;
	static const float kMaxTemperature;
private:
	float m_temperature;
};

