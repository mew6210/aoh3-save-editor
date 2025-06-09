#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "../utilities/utilities.hpp"





class Config{

    public:
    std::map<std::string,std::string> properties;


    Config(){}

    void addProperty(std::string s){

        properties.insert({s,""});

    }
    void addProperty(std::string s1,std::string s2){

        trim(s1);
        trim(s2);
        properties.insert({s1,s2});

    }

    void printProperties(){

        for(auto& property:properties){
            printf("Property: %s Value: %s",property.first.c_str(),property.second.c_str());
        }


    }


};

Config initConfig();