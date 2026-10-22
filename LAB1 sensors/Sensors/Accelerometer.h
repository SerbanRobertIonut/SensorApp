#pragma once
#include "Sensor.h"
class Accelerometer : public Sensor
{
public:
	Accelerometer(uint16_t id, SensorType type, const std::string& timestamp, bool status, float xAcceleration, float yAcceleratiron, float zAcceleration);
private:
	static const float kMinValidValue;
	static const float kMaxValidValue;
private:
	float m_xAcceleration;
	float m_yAcceleration;
	float m_zAcceleration;
};

