#include "Parser.h"

const std::string CONFIG_FILE_NAME = ".config.json";

extern AsciiArt art;
extern WORD weather_color;

std::string ParseLocalTime(std::string raw_local_time) {
	std::string result = "";
	for (int i = 0; raw_local_time[raw_local_time.size() - i] != ' '; ++i) {
		result.insert(result.begin(), raw_local_time[raw_local_time.size() - i]);
	}
	return result;
}

WeatherInfo ParseResponse(std::string raw_response) {
	WeatherInfo result;
	Log logs;

	if (raw_response == "") {
		PrintColorText(FOREGROUND_RED, "Invalid Link\n");
		logs.logging("Invalid Link");
		exit(1);
	}
	try {
		json parsed = json::parse(raw_response);
		std::string local_time = ParseLocalTime(parsed["location"]["localtime"]);
		result = WeatherInfo( local_time,
							  parsed["current"]["condition"]["code"],
							  parsed["current"]["condition"]["text"].get<std::string>(),
							  parsed["current"]["temp_c"],
							  parsed["current"]["feelslike_c"],
							  parsed["current"]["humidity"],
							  parsed["current"]["uv"],
							  parsed["current"]["wind_kph"],
							  parsed["current"]["pressure_mb"]);
	}
	catch (std::exception& ex) {
		PrintColorText(FOREGROUND_RED, "Invalid Link\n");
		logs.logging(ex.what());
		exit(2);
	}
	return result;
}

Config ParseConfigFile() {
	std::fstream config_file(CONFIG_FILE_NAME, std::ios::in);
	if (!config_file.is_open()) {
		PrintColorText(FOREGROUND_RED, "error: !config_file.is_open()");
		Log logs;
		logs.logging("error: !config_file.is_open()");
		exit(3);
	}
	Config config;
	try {
		json parsed = json::parse(config_file);
		config.little_iformation_flag = parsed["little_information"].get<bool>();
		config.location = parsed["location"].get<std::string>();
	}
	catch (std::exception& ex) {
		Log logs;
		logs.logging("error: json::parse(config_file)");
		PrintColorText(FOREGROUND_RED, "invalid config file");
		exit(4);
	}

#ifdef DEBUG
	std::cout << config.little_iformation_flag << " " << config.location << std::endl;
#endif // DEBUG


	return config;
}


std::string* ParseConditionCode(int code) {
	if (code == 1000) {
		weather_color = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN; //yellow
		return art.sunny;
	}
	if (code == 1003) {
		weather_color = FOREGROUND_INTENSITY; // grey
		return art.partial_clouds;
	}
	if (code == 1006 || code == 1009) {
		weather_color = FOREGROUND_INTENSITY; // grey
		return art.clouds;
	}
	if (code == 1030 || code == 1135 || code == 1147) {
		weather_color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; //dark grey
		return art.fog;
	}
	if (code == 1063 || code == 1180 || code == 1183 || code == 1186 || code == 1189 || code == 1192 ||
		code == 1195 || code == 1198 || code == 1201 || code == 1240 || code == 1243 || code == 1246) {
		weather_color = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE; // cyan
		return art.rain;
	}
	if (code == 1066 || code == 1114 || code == 1210 || code == 1213 || code == 1216 || code == 1219 ||
		code == 1222 || code == 1225 || code == 1255 || code == 1258 || code == 1069 || code == 1204 ||
		code == 1207 || code == 1249 || code == 1252 || code == 1237 ||
		code == 1261 || code == 1264) {
		weather_color = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; // white
		return art.snow;
	}
	if (code == 1273 || code == 1276 || code == 1279 || code == 1282 || code == 1087) {
		weather_color = FOREGROUND_GREEN | FOREGROUND_BLUE; // dark cyan
		return art.thunderstorm;
	}
	if (code == 1072 || code == 1150 || code == 1153 || code == 1168 || code == 1171) {
		weather_color = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE; // cyan
		return art.drizzle;
	}
	if (code == 1117) {
		weather_color = FOREGROUND_INTENSITY; // grey
		return art.wind;
	}
}
