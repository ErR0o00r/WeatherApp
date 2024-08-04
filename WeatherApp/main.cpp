#include <iostream>
#include <thread>
#include <conio.h>
#include "Request.h"
#include "Weather.h"
#include "Parser.h"

// яемевйю, ъ реаъ нвемэ яхкэмн кчакч <3 <3 <3
// ESENIIA, I LOVE YOU SO MUCH <3 <3 <3

void ServerPoll(WeatherInfo& weather) {
	WeatherInfo tmp;
	Request request;
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

	std::cout << "To exit press e" << std::endl;
	Sleep(1000);

	std::thread thread([&]() {
		while (true) {
			system("CLS");
			ServerPoll(weather);
			PrintWeatherInfo(weather.GetWeatherInfo());
			Sleep(1000 * 60 * 10);
		}
						});
	
	do {
		pressed_key = _getch();
	} while (pressed_key != 101);
	
	thread.detach();
	return 0;
}