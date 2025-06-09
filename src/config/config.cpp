#include "config.hpp"


const std::vector<std::string> CONFIG_PROPERTIES={"AOH3_location"};


Config readConfig(){

    Config config=Config();
    std::ifstream file("config.txt");
    std::string line="";

    while(std::getline(file,line)){
        int doublePeriodPosition=line.find(":");
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
        std::cout<<"reading file";
        return readConfig();
        
    }
    else{
        std::cout<<"creating file";
        return createConfig();
    }

}