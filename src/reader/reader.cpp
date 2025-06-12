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


/*
Returns a vector of directories that are saves, if path is wrong returns an empty vector.
*/
std::vector<std::string> getAvalibleSaves(const std::string& gamePath){

    std::vector<std::string> saves;
    std::string savesPath=AppendSavesDir(gamePath);
    
    try{

        auto directory_iterator=fs::directory_iterator(savesPath);

        for (const auto & entry : directory_iterator)
        {
            if(entry.is_directory()){
                saves.push_back(entry.path().filename().string());
         }
            
        }
            return saves;
    }
    catch(fs::filesystem_error& err){    //in case the path is wrong, notify the user about that
        warningLog("Path to game files is incorrect, couldn't find saves folder in it. Make sure it is correct");
        warningLog(err.what());
        return saves;
    }
        

  
        


}