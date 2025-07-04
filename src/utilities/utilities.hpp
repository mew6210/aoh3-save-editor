#include <algorithm> 
#include <cctype>
#include <locale>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>

void trim(std::string &s);


void successLog(const std::string& s);
void errorLog(const std::string& s);
void warningLog(const std::string& s);
void formatSaves(std::vector<std::string>& saves);