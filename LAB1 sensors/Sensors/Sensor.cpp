#include "Sensor.h"
#include <fstream>
#include <iostream>
// lista de initializare pentru a evita o copiere in plus
// {} in loc de () pentru a evidentia diferenta intre apelarea functiei si initializarea variabilelor
Sensor::Sensor(uint16_t id, SensorType type, const std::string& timestamp, bool status)
	:m_id{ id }, m_type{ type }, m_timestamp{ timestamp }, m_status{ status } {
}

