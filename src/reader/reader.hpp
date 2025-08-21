#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include <filesystem>
#include "../utilities/utilities.hpp"


using json=nlohmann::json;


enum PropertyType{
    pt_Number,
    pt_String,
    pt_Boolean
};

class JsonProperty{
public:
    std::string value;
    PropertyType type;

    JsonProperty(std::string& c_value,PropertyType& c_type):value(c_value),type(c_type){}

};

class DetailsStructure{
public:

    std::unordered_map<std::string,JsonProperty> structure;


    void loadStructure(std::filesystem::path& path);
    void writeStructure(std::filesystem::path& path);
    
};


std::vector<std::string> getAvalibleSaves(const std::string& gamePath);