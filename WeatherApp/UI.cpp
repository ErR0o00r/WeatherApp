#include "UI.h"

AsciiArt art;

WORD weather_color;

void PrintWeatherInfo(Weather weather, bool little_information_flag) {
	std::string* art = ParseConditionCode(weather.condition_code);
	SetConsoleTextColor(weather_color);
	if (little_information_flag) {
		std::cout << art[0] << "  " << weather.local_time << "\t" << weather.condition << std::endl;
		std::cout << art[1] << "  " << weather.temp << " C\t" << "feels like " << weather.feels_like << " C" << std::endl;
		std::cout << art[2] << "  " << weather.uv << " uv\t" << "wind speed " << weather.wind_speed << "kph" << std::endl;
	}
	else {
		std::cout << art[0] << std::endl << art[1] << std::endl << art[2] << std::endl;
		std::cout << weather.local_time << "\t" << weather.condition << std::endl;
		std::cout << weather.temp << " C\t" << "feels like " << weather.feels_like << " C" << std::endl;
		std::cout << weather.uv << " uv\t" << "wind speed " << weather.wind_speed << "kph" << std::endl;
		std::cout << "humidity " << weather.humidity << std::endl;
		std::cout << weather.pressure << " mmHg" << std::endl;
	}
	SetConsoleTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

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
