#pragma once
#include "Request.h"
#include "Parser.h"
#include <string>

class WeatherInfo {
private:
	std::string condition = "";

	int temp = NULL;

	int feels_like = NULL;

	int humidity = NULL;

	int uv = NULL;

	int wind_speed = NULL;

	int pressure = NULL;

public:
	WeatherInfo() = default;
	
	WeatherInfo(std::string condition, int temp, int feels_like, int humidity, int uv, int wind_speed, int pressure);
	
	void operator=(const WeatherInfo& other);

	void PrintWeather();
};
