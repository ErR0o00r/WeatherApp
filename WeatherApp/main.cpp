#include <iostream>
#include "Request.h"
#include "Weather.h"
#include "Parser.h"
#include "UI.h"


void ServerPoll(WeatherInfo& weather) {
	Request request;
	request.SendRequest();
	std::string raw_response = request.GetResponse();
	weather = ParseResponse(raw_response);
}
 
int main() {
	WeatherInfo weather;
	ServerPoll(weather);
	PrintWeatherInfo(weather);
	return 0;
}