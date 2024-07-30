#pragma once
#include <nlohmann/json.hpp>
#include "Weather.h"
#include <string>

using json = nlohmann::json;

class WeatherInfo;

WeatherInfo ParseResponse(std::string raw_response);