#include "main.h"
using json=nlohmann::json;


int main(){

    Config config = initConfig();

    config.printProperties();



    return 0;

}