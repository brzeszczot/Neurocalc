#ifndef CURL_HPP_INCLUDED
#define CURL_HPP_INCLUDED

#include <curl/curl.h>
#include "Base64.hpp"
#include "md5.hpp"

#define SEED "j89fd2438f8d2323m89x32m923mx92332d"

using namespace std;

int writer(char *data, size_t size, size_t nmemb, string *buffer);
string Go(string var);

#endif // CURL_HPP_INCLUDED
