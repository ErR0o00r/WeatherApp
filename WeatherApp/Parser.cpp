#include "Parser.h"

WeatherInfo ParseResponse(std::string raw_response) {
	json parsed = json::parse(raw_response);
	return WeatherInfo(parsed["current"]["condition"]["text"].get<std::string>(),
					   parsed["current"]["temp_c"],
					   parsed["current"]["feelslike_c"],
					   parsed["current"]["humidity"], 
					   parsed["current"]["uv"],
					   parsed["current"]["wind_kph"],
					   parsed["current"]["pressure_mb"]);
}
