#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include <filesystem>


using json=nlohmann::json;


std::vector<std::string> getAvalibleSaves(const std::string& gamePath);