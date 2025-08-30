#include "utilities.hpp"

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



bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}


namespace{
bool shouldAddDot(const string& left,const string& right){

    if(is_number(left)&&is_number(right)) return true;
    else return false;

}
/*
returns a string that is the result of merging the vector of words together, like it would be a format <country> dd.mm.yyyy
*/
string mergeWithDots(vector<string>& words){
    
    string save="";

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
    return save;
}
string replaceSeparatorWithSpace(string& save,const char separator){

    string transformed_save="";
    for(int i=0;i<save.length();i++){
        if(save[i]==separator) transformed_save+=" ";
        else transformed_save+=save[i];
    }
    return transformed_save;
}

}
/*
returns a list of words that exist in a save, that are separated by separator.
*/
vector<string> getWords(string& save,const char separator){

    string transformed_save = replaceSeparatorWithSpace(save,'_');
    std::stringstream stream(transformed_save);
    string word="";
    vector<string> words={};
    while(stream>>word){
        words.push_back(word);
    }



    return words;

}


void replaceFloorsWithDots(string& save){
    
    auto words=getWords(save,'_');
    save=mergeWithDots(words);

}


void addIterator(string& save,const int& iterator){

    save=std::to_string(iterator)+". "+save;

}


void formatSave(string& save){
    replaceFloorsWithDots(save);

    static int it=1;
    addIterator(save,it);
    it++;
}


void formatSaves(vector<string>& saves){

    for(auto& save:saves){
        formatSave(save);
    }


}