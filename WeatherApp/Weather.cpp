#include "Weather.h"

//вкееееееееееееееееееееем
//с лемъ б оное

void WeatherInfo::operator=(const WeatherInfo& other) {
	this->condition = other.condition;
	this->feels_like = other.feels_like;
	this->humidity = other.humidity;
	this->pressure = other.pressure;
	this->temp = other.temp;
	this->uv = other.uv;
	this->wind_speed = other.wind_speed;
}

void Weather::GetWeather() {
	request.SendRequest();
	weather_info = Parse(request.GetResponse());
}

void Weather::PrintWeather() {
	std::cout << "Condition: " << weather_info.condition << std::endl;
	std::cout << "feels like: " << weather_info.feels_like << std::endl;
	std::cout << "humidity: " << weather_info.humidity << std::endl;
	std::cout << "pressure: " << weather_info.pressure << std::endl;
	std::cout << "temp: " << weather_info.temp << std::endl;
	std::cout << "uv: " << weather_info.uv << std::endl;
	std::cout << "wind_speed: " << weather_info.wind_speed << std::endl;
}
