#include "logging.h"

extern const std::string LOG_FILE_NAME;

Log::Log() {
	_file.open(LOG_FILE_NAME, std::ios::out | std::ios::app);
	if (!_file.is_open()) {
		throw std::runtime_error("!file.is_open()");
	}

	std::cout << "file open" << std::endl;
}

Log::~Log() {
	if (_file.is_open()) {
		_file.close();
		std::cout << "file close" << std::endl;
	}

}

void Log::logging(std::string message) {
	sec_counter = time(NULL);
	localtime_s(&current_time, &sec_counter);
	_file << "[ " << current_time.tm_wday << "." << current_time.tm_mon << "." << 1900 + current_time.tm_year << " ]" << " [ " << current_time.tm_hour << ":" << current_time.tm_min << " ] " << message << std::endl;
	//tm_year return the year from 1900, so I add 1900 for correct display
}