#include "main.h"


using json=nlohmann::json;
using std::vector, std::string;

int main(){

    Config config = initConfig();

    if(checkConfigValidity(config)==0) successLog("Config is good");
    else errorLog("Something went wrong with config");

    vector<string> saves= getAvalibleSaves(config["AOH3_Game_Location"]);






    return 0;

}