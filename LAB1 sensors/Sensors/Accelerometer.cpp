#include "Accelerometer.h"

const float Accelerometer::kMaxValidValue = 10000;
const float Accelerometer::kMinValidValue = 10000;

Accelerometer::Accelerometer(uint16_t id, SensorType type, const std::string& timestamp, bool status, float xAcceleration, float yAcceleratiron, float zAcceleration)
	: Sensor(id, type, timestamp, status), m_xAcceleration(xAcceleration), m_yAcceleration(yAcceleratiron), m_zAcceleration(zAcceleration)
{
}
