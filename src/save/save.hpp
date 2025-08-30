#pragma once
#include <string>
#include <filesystem>
#include "../utilities/utilities.hpp"

class Save{
public:
    std::string name_raw;
    std::string name_formatted;
    std::filesystem::path path_to_save;

    
    Save(const std::string& c_name_raw,const std::filesystem::path& c_game_path):name_raw(c_name_raw){
        name_formatted = name_raw;
        formatSave(name_formatted);
        path_to_save = c_game_path / "saves" / "Earth3" / name_raw;
    }
    
    void printSave();
};