#include "Parser.h"

WeatherInfo ParseResponse(std::string raw_response) {
	
	if (raw_response == "") {
		PrintColorText(FOREGROUND_RED, "Invalid Link");
		exit(1);
	}

	json parsed = json::parse(raw_response);
	return WeatherInfo( parsed["current"]["condition"]["code"]
						parsed["current"]["condition"]["text"].get<std::wstring>(),
						parsed["current"]["temp_c"],
						parsed["current"]["feelslike_c"],
						parsed["current"]["humidity"], 
						parsed["current"]["uv"],
						parsed["current"]["wind_kph"],
						parsed["current"]["pressure_mb"]);
}
