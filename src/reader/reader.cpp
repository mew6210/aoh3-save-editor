#include "reader.hpp"

namespace fs = std::filesystem;


std::string AppendSavesDir(const std::string& gamePath){

    fs::path gameDir=gamePath;
    fs::path saves="saves";
    fs::path earth3="Earth3";
    fs::path target_dir=gameDir / saves;

    target_dir = target_dir / earth3;

    return target_dir.string();

}



std::vector<std::string> getAvalibleSaves(const std::string& gamePath){

    std::vector<std::string> lol;
    std::string savesPath=AppendSavesDir(gamePath);

    for (const auto & entry : fs::directory_iterator(savesPath))
    {
        if(entry.is_directory()){
            lol.push_back(entry.path().filename().string());
        }
            
    }
        

  
        
    return lol;

}