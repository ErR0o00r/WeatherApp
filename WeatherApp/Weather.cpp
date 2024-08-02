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


int WeatherInfo::GetConditionCode() const {
	return condition_code;
}

std::string WeatherInfo::GetCondition() const {
	return condition;
}

int WeatherInfo::GetTemp() const {
	return temp;
}

int WeatherInfo::GetFeelsLike() const {
	return feels_like;
}

int WeatherInfo::GetHumidity() const {
	return humidity;
}

int WeatherInfo::GetUv() const {
	return uv;
}

int WeatherInfo::GetWindSpeed() const {
	return wind_speed;
}

int WeatherInfo::GetPressure() const {
	return pressure;
}
