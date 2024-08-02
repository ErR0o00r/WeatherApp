#pragma once
#include "Request.h"
#include "Parser.h"
#include <string>
#include "UI.h"

class WeatherInfo {
private:
	int condition_code = NULL;

	std::string condition = "";

	int temp = NULL;

	int feels_like = NULL;

	int humidity = NULL;

	int uv = NULL;

	int wind_speed = NULL;

	int pressure = NULL;

public:

	int GetConditionCode() const;

	std::string GetCondition() const;

	int GetTemp() const;

	int GetFeelsLike() const;
	
	int GetHumidity() const;

	int GetUv() const;

	int GetWindSpeed() const;

	int GetPressure() const;

	WeatherInfo() = default;

	WeatherInfo(int condition_code, std::string condition, int temp, int feels_like, int humidity, int uv, int wind_speed, int pressure);

	void operator=(const WeatherInfo& other);

};
