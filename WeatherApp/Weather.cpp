#include "Weather.h"


WeatherInfo::WeatherInfo(int condition_code, std::string condition, int temp, int feels_like, int humidity, int uv, int wind_speed, int pressure) {
	this->condition_code = condition_code;
	this->condition = condition;
	this->temp = temp;
	this->feels_like = feels_like;
	this->humidity = humidity;
	this->uv = uv;
	this->wind_speed = wind_speed;
	this->pressure = pressure;
}

void WeatherInfo::operator=(const WeatherInfo& other) {
	this->condition_code = other.condition_code;
	this->condition = other.condition;
	this->temp = other.temp;
	this->feels_like = other.feels_like;
	this->humidity = other.humidity;
	this->uv = other.uv;
	this->wind_speed = other.wind_speed;
	this->pressure = other.pressure;
}

#ifdef DEBUG
void WeatherInfo::PrintWeather() {
	std::cout << "condition: " << this->condition << std::endl;
	std::cout << "temp: " << this->temp << std::endl;
	std::cout << "feels like: " << this->feels_like << std::endl;
	std::cout << "humidity: " << this->humidity << std::endl;
	std::cout << "uv: " << this->uv << std::endl;
	std::cout << "wind speed: " << this->wind_speed << std::endl;
	std::cout << "pressure: " << this->pressure << std::endl;
}
#endif // DEBUG


