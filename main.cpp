#include "main.h"
#include "raylib.h"

using json=nlohmann::json;
using std::vector, std::string;

int main(){

    Config config = initConfig();

    if(checkConfigValidity(config)==0) successLog("Config is good");
    else errorLog("Something went wrong with config");

    vector<string> saves= getAvalibleSaves(config["AOH3_Game_Location"]);


    InitWindow(800, 450, "AOH3 Save Editor");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Ligma", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();



    return 0;

}