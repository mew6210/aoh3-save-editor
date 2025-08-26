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
    pt_Boolean,
    pt_NULL
};

class JsonProperty{
public:
    std::string value;
    PropertyType type;

    JsonProperty(const std::string& c_value,const PropertyType& c_type):value(c_value),type(c_type){}
    JsonProperty(){
        value = "NULL";
        type = pt_NULL;
    }

};

class DetailsStructure{
public:

    std::unordered_map<std::string,JsonProperty> structure;


    void loadStructure(const std::filesystem::path& path);
    void writeStructure(const std::filesystem::path& path);
    void printStructure();
};


std::vector<std::string> getAvalibleSaves(const std::string& gamePath);
std::filesystem::path appendDetailsJsonToPath(const std::filesystem::path& path);