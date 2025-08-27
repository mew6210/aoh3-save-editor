#pragma once
#include <string>
#include <filesystem>
#include "../utilities/utilities.hpp"

class Save{
public:
    std::string name_raw;
    std::string name_formatted;
    std::filesystem::path path_to_save;

    
    Save(const std::string& c_name_raw):name_raw(c_name_raw){}
    void formatNames();
};