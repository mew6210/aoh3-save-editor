#include "config.hpp"


const std::vector<std::string> CONFIG_PROPERTIES={"AOH3_Game_Location"};


Config readConfig(){

    Config config=Config();
    std::ifstream file("config.txt");
    std::string line="";

    while(std::getline(file,line)){
        size_t doublePeriodPosition=line.find(":");
        std::string property=line.substr(0,doublePeriodPosition);
        std::string value=line.substr(doublePeriodPosition+1);
        config.addProperty(property,value);

    }

    return config;

}

Config createConfig(){

    Config config=Config();
    std::ofstream file("config.txt");

    for(std::string property:CONFIG_PROPERTIES){

        file<<property;
        file<<":";
        file<<"\n";
        config.addProperty(property);

    }
    file.close();

    return config;

}

Config initConfig(){


    std::ifstream file("config.txt");
    bool doesConfigExist=file.is_open();
    

    if(doesConfigExist==true){
        return readConfig();
        
    }
    else{
        return createConfig();
    }

}

int checkIfNotEmpty(Config config){

    for(auto& property:CONFIG_PROPERTIES){
        if(config[property]==""|| config[property]=="not found"){
            errorLog(property+" is empty, make sure to fill out config properly first");
            return 1;
        }
    }
    return 0;
}

/*
returns 0, if everything is good
returns 1, if any of the property is empty
*/
int checkConfigValidity(Config c){

    if(checkIfNotEmpty(c)!=0){
        return 1;
    }
    //other validity checks

    return 0;

}