#pragma once
#include "Request.h"
#include "Parser.h"
#include <string>
#include "UI.h"

struct Weather {
	std::string condition = "";

	std::string local_time = "";

	int temp = NULL;

	int feels_like = NULL;

	int humidity = NULL;

	int uv = NULL;

	int wind_speed = NULL;

	int pressure = NULL;
	
	int condition_code = NULL;
};

class WeatherInfo {
private:
	Weather weather_info;
public:

	WeatherInfo() = default;
	
	WeatherInfo(std::string local_time, int condition_code, std::string condition, int temp, int feels_like, int humidity, int uv, int wind_speed, int pressure);
	
	Weather GetWeatherInfo();

	void operator=(const WeatherInfo& other);

	bool IsEmpty();

};
