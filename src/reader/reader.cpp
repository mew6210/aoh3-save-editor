#include "reader.hpp"

namespace fs = std::filesystem;


std::string appendSavesDir(const std::string& gamePath){

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
std::vector<Save> getAvalibleSaves(const std::string& gamePath){


    std::vector<Save> saves;
    std::string savesPath=appendSavesDir(gamePath);
    
    try{
        auto directory_iterator=fs::directory_iterator(savesPath);

        for (const auto & entry : directory_iterator){
            if(entry.is_directory()){
                saves.push_back(
                    Save(
                        entry.path().filename().string(),
                        gamePath)
                );
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

fs::path appendDetailsJsonToPath(const fs::path& path){
    return path / "Details.json";
}


JsonProperty parseDetailsStructureRHS(const std::string& rhs){

    if(rhs.size()==0) return JsonProperty();
    
    PropertyType type;
    if(rhs[0]=='\"')                    type = pt_String;
    else if(rhs[0]=='t'||rhs[0]=='f')   type = pt_Boolean;
    else if(isdigit(rhs[0]))            type = pt_Number;
    else                                type = pt_NULL;
    
    return JsonProperty(rhs,type);
}

std::pair<std::string,JsonProperty> parseDetailsStructureLine(const std::string& line){

    size_t commaPos = line.find(":");
    std::string lhs = line.substr(0,commaPos);
    std::string rhs = line.substr(commaPos+1);
    trim(rhs);
    JsonProperty value = parseDetailsStructureRHS(rhs);
    
    return {lhs,value};     //key,value
}

void DetailsStructure::loadStructure(const std::filesystem::path& path){
    std::ifstream file(path);
    if (!file.is_open()) errorLog("wrong file path");
    
    std::string line = "";
    while(std::getline(file,line)){
        if(line == "{") continue;
        if(line == "}") continue;
        auto parsedLine = parseDetailsStructureLine(line);

        structure.insert(parsedLine);
    }
}

std::string propertyTypeToString(const PropertyType& type){
    switch(type){
        case pt_Boolean: return "Boolean";
        case pt_Number: return "Number";
        case pt_String: return "String";
        case pt_NULL: return "Null";    
        default: return "unkown";
    }
}

void DetailsStructure::printStructure(){
    for(const auto& [key,val]:structure){
        std::cout<<"key: "<<key<<" value: "<<val.value<<" value type: "<<propertyTypeToString(val.type)<<"\n";
    }
}

void writeDetailsLine(const std::pair<std::string,JsonProperty> line, std::ofstream& file) {
    file << line.first << ": " << line.second.value << "\n";
}

void DetailsStructure::writeStructure(const std::filesystem::path& path) {

    std::ofstream detailsFile(path);
    detailsFile << "{\n";
    for (auto& line : structure) {
        writeDetailsLine(line,detailsFile);
    }
    detailsFile << "}";
}


