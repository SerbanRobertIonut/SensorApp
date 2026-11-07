#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

#include "Accelerometer.h"
#include "Thermometer.h"

bool sensorTimestampComparator(const sensors::SensorData* s1, const sensors::SensorData* s2)
{
	return s1->GetTimestamp() > s2->GetTimestamp();
}

int main()
{
	using sensors::SensorData;
	using sensors::SensorType;
	using sensors::toSensorType;
	using sensors::Accelerometer;
	using sensors::Thermometer;


	std::vector<SensorData*> dataVector;

	for (std::ifstream file{ "../sensors.log" }; !file.eof();)
	{
		if (!file)
		{
			std::cout << "ifstream not in a good state!";
		}

		std::string id_str, type_str, timestamp;
		file >> id_str >> type_str >> timestamp;
		std::uint16_t id{ static_cast<std::uint16_t>(std::stoi(id_str.substr(1, 3))) };
		SensorType type{ toSensorType(type_str) };

		float value1{}, value2{}, value3{};
		std::string status_str;

		switch (type)
		{
		case SensorType::ACCM:
			file >> value1 >> value2 >> value3 >> status_str;
			dataVector.push_back(
				new Accelerometer{
					id, type, timestamp, status_str == "OK", value1, value2, value3
				}
			);
			break;
		case SensorType::TEMP:
			file >> value1 >> status_str;
			dataVector.push_back(
				new Thermometer{
					id, type, timestamp, status_str == "OK", value1
				}
			);
			break;
		}
	}

	
	for (const auto& sensor : dataVector)
	{
		auto month{ sensor->GetMonth() };
		if (sensor->IsMeasurementValid() && sensor->GetType() == SensorType::TEMP && month > 8u && month < 12u)
		{
			auto thermometer{ dynamic_cast<const Thermometer*>(sensor) };
			std::cout << *thermometer << '\n';
		}
	}
	std::cout << "\n\n";

	
	std::sort(dataVector.begin(), dataVector.end(), sensorTimestampComparator);
	for (const auto& sensor : dataVector)
	{
		std::cout << *sensor << '\n';
	}
	std::cout << "\n\n";

	for (auto data : dataVector)
	{
		delete data;
	}

	return 0;
}

