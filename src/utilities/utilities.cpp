#include "utilities.hpp"


// trim from start (in place)
inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}


void successLog(const std::string& s){
    printf("[OK] %s\n",s.c_str());
}

void errorLog(const std::string& s){
    printf("[!] %s\n",s.c_str());
    exit(1);
}

void warningLog(const std::string& s){
    printf("[?] %s\n",s.c_str());
}

