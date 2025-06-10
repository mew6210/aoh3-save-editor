#pragma once
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

    std::string getPropertyValue(std::string key) {


		if (properties.count(key) > 0) {

			std::string propertyValue = properties[key];
			trim(propertyValue);
			return propertyValue;
		}
		else {
			std::cout<<"Not found property in config: "<<key;
			return "not found";
		}


	}

    std::string operator[](std::string s) {
		return getPropertyValue(s);
	}





};

Config initConfig();


int checkConfigValidity(Config c);


class ConfigFileProperty{

public:
    std::vector<std::string> comments;
    std::string property;

    ConfigFileProperty(const std::vector<std::string>& comments1,std::string property1){
        comments=comments1;
        property=property1;
    };
    ConfigFileProperty(){};



};