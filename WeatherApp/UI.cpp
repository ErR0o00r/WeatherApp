#include "UI.h"

AsciiArt art;
WORD weather_color;

void PrintColorText(WORD color, std::string text) {
	HANDLE std_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_handle, color);
	std::cout << text << std::endl;
	SetConsoleTextAttribute(std_handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	CloseHandle(std_handle);
}

void SetConsoleTextColor(WORD color) {
	HANDLE std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_out, color);
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

void PrintWeatherInfo(Weather weather) {
	time_t now = time(NULL);
	tm current_time;
	localtime_s(&current_time, &now);

	std::string* art = ParseConditionCode(weather.condition_code);
	SetConsoleTextColor(weather_color);

	std::cout << art[0] << "  " << current_time.tm_hour << ":" << current_time.tm_min << "\t" << weather.condition << std::endl;
	std::cout << art[1] << "  " << weather.temp << " C" << "\t" << "feels like " << weather.feels_like << " C" << std::endl;
	std::cout << art[2] << "  " << weather.uv << " uv" << "\t" << "wind speed " << weather.wind_speed << "kph" << std::endl;

	SetConsoleTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}