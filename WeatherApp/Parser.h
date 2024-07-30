#pragma once
#include <nlohmann/json.hpp>
#include "Weather.h"
#include <string>

using json = nlohmann::json;

WeatherInfo Parse(std::string raw_response);