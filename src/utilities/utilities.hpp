#include <algorithm> 
#include <cctype>
#include <locale>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <sstream>

void trim(std::string &s);


void successLog(const std::string& s);
void errorLog(const std::string& s);
void warningLog(const std::string& s);
void formatSaves(std::vector<std::string>& saves);
void formatSave(std::string& save);