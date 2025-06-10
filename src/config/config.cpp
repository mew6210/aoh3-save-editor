#include "config.hpp"


const std::vector<ConfigFileProperty> CONFIG_PROPERTIES={ConfigFileProperty({"lines that start with # are ignored",
    R"(example for windows: C:\Program Files (x86)\Steam\steamapps\common\Age of History 3)",
    "example for linux: /home/<your_username>/.steam/steam/steamapps/common/Age of History 3",
    "for windows, DONT use double slashes"

},"AOH3_Game_Location")};


Config readConfig(){

    Config config=Config();
    std::ifstream file("config.txt");
    std::string line="";

    while(std::getline(file,line)){
        if (line[0]=='#') continue;
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

    for(ConfigFileProperty property:CONFIG_PROPERTIES){

        for(auto& comment:property.comments){
            file<<"#";
            file<<comment;
            file<<"\n";
        }
        file<<property.property;
        file<<":";
        file<<"\n";
        config.addProperty(property.property);

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
        if(config[property.property]==""|| config[property.property]=="not found"){
            errorLog(property.property+" is empty, make sure to fill out config.txt properly first");
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