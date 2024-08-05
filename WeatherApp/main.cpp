#include <iostream>
#include <thread>
#include <conio.h>
#include "Request.h"
#include "Weather.h"
#include "Parser.h"

// яемевйю, ъ реаъ нвемэ яхкэмн кчакч <3 <3 <3
// ESENIIA, I LOVE YOU SO MUCH <3 <3 <3

void ServerPoll(WeatherInfo& weather, Config& config) {
	WeatherInfo tmp;
	Request request(config.location);
	request.SendRequest();
	std::string raw_response = request.GetResponse();
	tmp = ParseResponse(raw_response);
	if (tmp.IsEmpty()) {
		Log logs;
		logs.logging("ServerPoll Error");
		return;
	}
	weather = tmp;
}
 
int main() {
	WeatherInfo weather;
	int pressed_key;
	Config config;
	std::thread thread_config_parse([&config]() {
		config = ParseConfigFile();
									});

	std::cout << "To exit press e" << std::endl;
	Sleep(1000);
	thread_config_parse.join();

	std::thread thread([&weather, &config]() {
		while (true) {
			system("CLS");
			ServerPoll(weather, config);
			PrintWeatherInfo(weather.GetWeatherInfo(), config.little_iformation_flag);
			Sleep(1000 * 60 * 10);
		}
						});
	
	do {
		pressed_key = _getch();
	} while (pressed_key != 101);
	
	thread.detach();

	return 0;
}