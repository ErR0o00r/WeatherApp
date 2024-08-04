#pragma once
#include <string>
#include <fstream>
#include <ctime>

#include <iostream>

const std::string LOG_FILE_NAME = "logs.txt";

class Log {
private:
	std::fstream _file;
	time_t sec_counter;
	tm current_time;
public:
	Log();
	~Log();
	void logging(std::string message);
};