#include <iostream>
#include "Request.h"
#include "Weather.h"
#include "Parser.h"

int main() {
	//CURL *handle;
	//CURLcode curl_code;
	//std::string response;
	//handle = curl_easy_init();
	//curl_global_init(CURL_GLOBAL_ALL);
	//handle = curl_easy_init();
	//if (handle) {
	//	curl_easy_setopt(handle, CURLOPT_URL, "https://api.weatherapi.com/v1/current.json?key=42b619da625b4e3e9ee173528242807&q=Novosibirsk&aqi=no");
	//	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, WriteFunction);
	//	curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);
	//}
	//curl_code = curl_easy_perform(handle);
	//if (curl_code != CURLE_OK) {
	//	std::cout << "error\n";
	//}
	//std::cout << response << std::endl;
	//curl_easy_cleanup(handle);
	
	Request request;
	request.SendRequest();
	std::string raw_response = request.GetResponse();
	WeatherInfo weather = ParseResponse(raw_response);
	weather.PrintWeather();

	return 0;
}