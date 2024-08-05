#include "Weather.h"


Weather WeatherInfo::GetWeatherInfo() {
	return weather_info;
}

WeatherInfo::WeatherInfo(std::string local_time, int condition_code, std::string condition, int temp, int feels_like, int humidity, int uv, int wind_speed, int pressure) {
	weather_info.local_time = local_time;
	weather_info.condition_code = condition_code;
	weather_info.condition = condition;
	weather_info.temp = temp;
	weather_info.feels_like = feels_like;
	weather_info.humidity = humidity;
	weather_info.uv = uv;
	weather_info.wind_speed = wind_speed;
	weather_info.pressure = pressure;
}

void WeatherInfo::operator=(const WeatherInfo& other) {
	this->weather_info = other.weather_info;
}

bool WeatherInfo::IsEmpty() {
	if (weather_info.condition_code == NULL && weather_info.condition == "" &&
		weather_info.feels_like == NULL && weather_info.humidity == NULL &&
		weather_info.uv == NULL && weather_info.wind_speed == NULL && weather_info.pressure == NULL) {
		return true;
	}
	return false;
}

