#include "Parser.h"

WeatherInfo Parse(std::string raw_response) {
    WeatherInfo result;
    json parsed = json::parse(raw_response);
    result.condition = parsed["condition"]["text"].get<std::string>();
    result.temp = parsed["current"]["temp_c"];
    result.feels_like = parsed["current"]["feelslike_c"];
    result.humidity = parsed["current"]["humidity"];
    result.uv = parsed["current"]["uv"];
    result.wind_speed = parsed["current"]["wind_kph"];
    result.pressure = parsed["current"]["pressure_mb"];
    return result;
}
