#include "Parser.h"

WeatherInfo ParseResponse(std::string raw_response) {
	WeatherInfo result;
	Log logs;

	if (raw_response == "") {
		PrintColorText(FOREGROUND_RED, "Invalid Link\n");
		logs.logging("Invalid Link");
		exit(1);
	}
	try {
		json parsed = json::parse(raw_response);
		result = WeatherInfo(parsed["current"]["condition"]["code"],
						   parsed["current"]["condition"]["text"].get<std::string>(),
						   parsed["current"]["temp_c"],
						   parsed["current"]["feelslike_c"],
						   parsed["current"]["humidity"],
						   parsed["current"]["uv"],
						   parsed["current"]["wind_kph"],
						   parsed["current"]["pressure_mb"]);
	}
	catch (std::exception& ex) {
		logs.logging(ex.what());
	}
	return result;
}
