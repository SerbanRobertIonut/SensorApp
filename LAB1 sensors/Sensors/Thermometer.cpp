#include "Thermometer.h"

const float Thermometer::kMaxTemperature = 300;
const float Thermometer::kMinTemperature = 0;

Thermometer::Thermometer(uint16_t id, SensorType type, const std::string& timestamp, bool status, float temperature) : Sensor(id,type,timestamp,status)
, m_temperature{temperature}
{
}

