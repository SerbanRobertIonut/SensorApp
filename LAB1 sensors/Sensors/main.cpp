#include "Sensor.h"
#include "Thermometer.h"
#include "Accelerometer.h"
#include <iostream>
#include <fstream>

int main()
{
	std::vector<Sensor*> sensors;
	std::ifstream f("sensors.txt");
	while (!f.eof())
	{
		std::string idStr, typeStr, timeStr, statusStr;
		f >> idStr >> typeStr >> timeStr;
		std::size_t noValues = typeStr == "TEMP" ? 1u : 3u;
		std::vector<float>values(noValues);
		for (int i = 0; i < noValues; i++)
		{
			f >> values[i];
		
		}
		f >> statusStr;
		uint16_t id = std::stoi(idStr.substr(1)); // IN CPP MODERN NU MAI E NEVOIE DE SUBSTR
		SensorType type = typeStr == "TEMP" ? SensorType::TEMP : SensorType::ACCM;
		bool status = statusStr == "OK";// ? true : false;
		//sensors.emplace_back(id, type, timeStr, values, status); asta era fara polimorfism...
		if (typeStr == "TEMP")
		{
			//Thermometer thermometer(id, type, timeStr, status, values[0]);
			//Thermometer* thermometer= new Thermometer (id, type, timeStr, status, values[0]);
			Sensor* thermometer= new Thermometer (id, type, timeStr, status, values[0]);
			sensors.push_back(thermometer);
		}
		
	}
	return 0;
}