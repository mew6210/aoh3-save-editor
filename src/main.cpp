#include "main.h"


using json=nlohmann::json;
using std::vector, std::string;

int main(){

    Config config = initConfig();
    
    if(checkConfigValidity(config)!=0) errorLog("Something went wrong with config");

    vector<Save> saves= getAvalibleSaves(config["AOH3_Game_Location"]);
    
    if(saves.empty()) warningLog("vector returned empty");
    
    for(auto& save:saves){
        save.formatNames();
    }

    

    drawingLoop(saves);



    return 0;

}