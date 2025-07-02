#include "utilities.hpp"
#include <numeric>

using std::string,std::vector;

// trim from start (in place)
inline void ltrim(string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void rtrim(string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
void trim(string &s) {
    rtrim(s);
    ltrim(s);
}


void successLog(const string& s){
    printf("[OK] %s\n",s.c_str());
}

void errorLog(const string& s){
    printf("[!] %s\n",s.c_str());
    exit(1);
}

void warningLog(const string& s){
    printf("[?] %s\n",s.c_str());
}

int getNextFloor(string& save,int previousPos,vector<string>& words){
    words.push_back(save.substr(0,previousPos));
    save=save.substr(previousPos+1);
    return save.find("_");
}

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

bool shouldAddDot(const string& left,const string& right){

    if(is_number(left)&&is_number(right)) return true;
    else return false;

}

void formatSave(string& save){

    vector<string> words;
    string origin_save=save;
    vector<int> positions={0};
    int pos=save.find("_");
    while(pos!=std::string::npos){
        positions.push_back(pos);
        pos=getNextFloor(save,pos,words);

    }
    words.push_back(save);

    save="";
    
    for(int i=0;i<words.size();i++){

        if(i+1==words.size()){
            save+=words[i];
            continue;
        }

        if(shouldAddDot(words[i],words[i+1])){
            save+=words[i]+".";
        }
        else{
            save+=words[i]+" ";
        }

    }

}






void formatSaves(vector<string>& saves){

    for(auto& save:saves){
        formatSave(save);
    }


}