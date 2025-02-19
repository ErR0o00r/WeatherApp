#include "Request.h"

size_t Request::WriteFunction(char* content, size_t size, size_t nmemb, void* userp) {
	((std::string*)userp)->append(content, size * nmemb);
	return size * nmemb;
}

Request::Request(std::string location) {
	curl_global_init(CURL_GLOBAL_ALL);
	handle = curl_easy_init();
	if (handle) {
		std::string link = "https://api.weatherapi.com/v1/current.json?key=42b619da625b4e3e9ee173528242807&q=" + location + "&aqi=no";
		curl_easy_setopt(handle, CURLOPT_URL, link.c_str());
		curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, Request::WriteFunction);
		curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);
	}
}

Request::~Request() {
	curl_easy_cleanup(handle);
	curl_global_cleanup();
}

void Request::SendRequest() {
	curl_code = curl_easy_perform(handle);
	if (curl_code != CURLE_OK) {
		PrintColorText(FOREGROUND_RED, "error\n");
		Log log;
		log.logging("error\n");
	}
}

std::string Request::GetResponse() {
	return response;
}

#ifdef DEBUG
void Request::PrintResponse() {
	std::cout << response << std::endl;
}
#endif DEBUG