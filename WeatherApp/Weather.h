#pragma once
#include "Request.h"
#include "Parser.h"
#include <string>


struct WeatherInfo {

		std::string condition = "";

		int temp = NULL;

		int feels_like = NULL;

		int humidity = NULL;

		int uv = NULL;

		int wind_speed = NULL;

		int pressure = NULL;

		WeatherInfo() = default;
		void operator=(const WeatherInfo& other);

};

class Weather {
private:

	Request request;

	WeatherInfo weather_info;

public:

	void GetWeather();

	void PrintWeather();

};