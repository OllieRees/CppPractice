#include "word.hpp"
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


std::set<char> Word::get_characters() const {
    return std::set<char>(this -> word.begin(), this -> word.end());
}


bool Word::contains_character(char c) const {
    return this -> word.find(c) != std::string::npos;
}



size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

Word* WordGeneratorAPI::generate_word() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://random-word-api.vercel.app/api?words=1");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: "
                      << curl_easy_strerror(res) << std::endl;
        } 

        curl_easy_cleanup(curl);
    }
    json j = json::parse(readBuffer);
    return new Word(j[0]);
}