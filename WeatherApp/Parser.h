#pragma once
#include <nlohmann/json.hpp>
#include "Weather.h"
#include "UI.h"
#include <string>
#include <fstream>

using json = nlohmann::json;

class WeatherInfo;

struct Config {
	std::string location;
	bool little_iformation_flag;
};


std::string ParseLocalTime(std::string raw_local_time);

WeatherInfo ParseResponse(std::string raw_response);

Config ParseConfigFile();

std::string* ParseConditionCode(int code);
