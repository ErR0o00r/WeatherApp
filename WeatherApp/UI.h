#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

struct AsciiArt {
	std::string sunny[3] = { "  \\ | /   ",
							 "  - O -   ",
							 "  / | \\   " };

	std::string partial_clouds[3] = { "  \\ /(  ) ",
									  " - O(    )",
									  "  / (  )  ",
	};

	std::string clouds[3] = { "  ( )()_  ",
							  " (      ) ",
							  "  (  )()  "
	};

	std::string drizzle[3] = { " '  '    '",
							   "  '   ' ' ",
							   "'    '   '"
	};

	std::string rain[3] = { " ' '' ' ' ",
							" '' ' ' ' ",
							" ' ' '' ' "
	};

	std::string thunderstorm[3] = { " ''_/ _/' ",
									" ' / _/' '",
									" /_/'' '' "
	};

	std::string snow[3] = { " * '* ' * ",
						    " '* ' * ' ",
						    " *' * ' * "
	};

	std::string fog[3] = { " -- _ --  ",
						   " -__-- -  ",
						   " - _--__  "
	};

	std::string wind[3] = { " c__ -- _ ",
							" -- _-c__ ",
							" c --___c "
	};
};

void PrintColorText(WORD color, std::string text);

std::string* ParseConditionCode(int code);