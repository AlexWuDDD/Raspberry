//
// Created by wkjwo on 7/18/2019.
//

#ifndef DISPLAYAPP_LIBCURL_H
#define DISPLAYAPP_LIBCURL_H
#include <iostream>
#include <string>
#include "curl/curl.h"

using namespace std;


#pragma comment(lib, "ssleay32.lib")
#pragma comment(lib, "libcurl.lib")

string AsciiToUtf8(const string& str);
string Utf8ToAscii(const string& str);

int HttpGet(const char* url, std::string &respData);
int HttpPost(char* url, char* body);
int HttpDownload(char* url,  char* filePath);

#endif //DISPLAYAPP_LIBCURL_H
