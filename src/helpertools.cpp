#include "helpertools.h"
#include <cstring>
#include <curl/curl.h>
#include <iostream>
#include <vector>

using namespace std;

void test(){

};

// Utility function to help curl
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string *data) {
    data->append((char *)ptr, size * nmemb);
    return size * nmemb;
};


std::pair<std::string, std::string> httpGet(std::string url) {
    auto response  = std::string("");
    auto curl      = curl_easy_init();
    std::string error_message{""};
    long http_code = 0;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(
            curl, CURLOPT_USERAGENT,
            "Mozilla/5.0 (Macintosh; Intel Mac OS X 11_3_1) AppleWebKit/537.36 (KHTML, "
            "like Gecko) Chrome/90.0.4430.93 Safari/537.36");
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        curl = nullptr;
    }
    if (http_code != 200) {
        response = "";
        error_message = "error in processing url: " + url;
    }

    return std::make_pair(response, error_message);
};