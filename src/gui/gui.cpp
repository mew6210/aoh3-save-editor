#include "gui.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


void drawingLoop(std::vector<Save>& saves){

    Rectangle buttonBounds={24,24,120,30};


    SetConfigFlags(FLAG_WINDOW_RESIZABLE);


    InitWindow(800, 450, "AOH3 Save Editor");
    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
            BeginDrawing();
            showLeftPanel();


            ClearBackground(RAYWHITE);
            DrawText("Ligma", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

}