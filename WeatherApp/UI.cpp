#include "UI.h"

void PrintColorText(WORD color, std::string text) {
	HANDLE std_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_handle, color);
	std::cout << text << std::endl;
	SetConsoleTextAttribute(std_handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	CloseHandle(std_handle);
}

std::string* ParseConditionCode(int code) {
	AsciiArt art

	if (code == 1000) {
		return art.sunny;
	}
	if (code == 1003) {
		return art.partial_clouds;
	}
	if (code == 1006 || code == 1009) {
		return art.clouds;
	}
	if (code == 1030 || code == 1135 || code == 1147) {
		return art.fog;
	}
	if (code == 1063 || code == 1180 || code == 1183 || code == 1186 || code == 1189 || code == 1192 ||
		code == 1195 || code == 1198 || code == 1201 || code == 1240 || code == 1243 || code == 1246) {
		return art.rain;
	}
	if (code == 1066 || code == 1114 || code == 1210 || code == 1213 || code == 1216 || code == 1219 ||
		code == 1222 || code == 1225 || code == 1255 || code == 1258 || code == 1069 || code == 1204 || 
		code == 1207 || code == 1249 || code == 1252 || code == 1237 ||
		code == 1261 || code == 1264) {
		return art.snow;
	}
	if (code == 1273 || code == 1276 || code == 1279 || code == 1282 || code == 1087) {
		return art.thunderstorm;
	}
	if (code == 1072 || code == 1150 || code == 1153 || code == 1168 || code == 1171) {
		return art.drizzle;
	}
	if (code == 1117) {
		return art.wind;
	}
}
