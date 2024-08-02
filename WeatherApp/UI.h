#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <ctime>
#include "Weather.h"

class WeatherInfo;

struct AsciiArt {
	std::wstring sunny[3] = {"  \\ | /   ",
							 "  - O -   ",
							 "  / | \\   " };

	std::wstring partial_clouds[3] = {"  \\ /(  ) ",
									  " - O(    )",
									  "  / (  )  ",
	};
	std::wstring clouds[3] = { L"  ( )()_  ",
							   L"  (  )()  "
							   L" (      ) ",
	};

	std::wstring drizzle[3] = { L" '  '    '",
							    L"  '   ' ' ",
							    L"'    '   '"
	};

	std::wstring rain[3] = { L" ' '' ' ' ",
							 L" '' ' ' ' ",
							 L" ' ' '' ' "
	};

	std::wstring thunderstorm[3] = { L" ''_/ _/' ",
									 L" ' / _/' '",
									 L" /_/'' '' "
	};

	std::wstring snow[3] = { L" * '* ' * ",
						     L" '* ' * ' ",
						     L" *' * ' * "
	};

	std::wstring fog[3] = { L" -- _ --  ",
						    L" -__-- -  ",
						    L" - _--__  "
	};

	std::wstring wind[3] = { L" c__ -- _ ",
							 L" -- _-c__ ",
							 L" c --___c "
	};
};

void PrintColorText(WORD color, std::string text);

void PrintWeatherInfo(WeatherInfo& weather);

std::wstring* ParseConditionCode(int code);
