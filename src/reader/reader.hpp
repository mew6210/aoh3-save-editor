#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include <filesystem>
#include "../utilities/utilities.hpp"


using json=nlohmann::json;


std::vector<std::string> getAvalibleSaves(const std::string& gamePath);