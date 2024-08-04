#pragma once
#include <curl/curl.h>
#include <string>
#include <iostream>
#include "UI.h"
#include "Logging.h"


class Request {
private:
	CURL* handle;
	CURLcode curl_code;
	std::string response = "";

public:
	static size_t WriteFunction(char* content, size_t size, size_t nmemb, void* userp);

	Request();

	~Request();

	void SendRequest();

	std::string GetResponse();

#ifdef DEBUG
	void PrintResponse();
#endif // DEBUG

};