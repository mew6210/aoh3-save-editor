#include "savesPanel.hpp";

#include "raygui.h"

#ifndef RAYGUI_IMPLEMENTATION
#define RAYGUI_IMPLEMENTATION
#endif




void showSavesPanel(std::vector<std::string>& saves){


 


    static int saveHeight=28;
    static int windowHeight =GetScreenHeight();
    static int windowWidth =GetScreenWidth();
    static Rectangle panelView={0};
    static Vector2 scroll={0,0};
    static Rectangle bounds={0,0,windowWidth*0.3,windowHeight};
    static Rectangle scrollBounds={0,0,(windowWidth*0.3)-15,windowHeight+(saves.size()*saveHeight)};



    GuiScrollPanel(bounds,"Saves",scrollBounds,&scroll,&panelView);
    GuiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_LEFT);    // align text to the left
    GuiSetStyle(BUTTON, TEXT_PADDING, 0);                    // reduce padding
    GuiSetStyle(BUTTON, BORDER_WIDTH, 0);                    // remove border
    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(Color{245,245,245,0}));       
    GuiSetStyle(BUTTON, BASE_COLOR_FOCUSED, ColorToInt(LIGHTGRAY));      // hover color
    GuiSetStyle(BUTTON, BASE_COLOR_PRESSED, ColorToInt(GRAY));   
    
    static Vector2 mouse = GetMousePosition();


    for(int i=0;i<saves.size();i++){

        float yPos=10+scroll.y+(i*saveHeight);

        if(yPos+saveHeight>panelView.y&&yPos+saveHeight<panelView.y+panelView.height){
            
            Rectangle labelRect=Rectangle{0,
                yPos,
                (float)MeasureText(saves[i].c_str(),10)
                ,50
            };
            if(GuiLabelButton(labelRect,saves[i].c_str())){
                printf("pressed");
            }
        }

    }
       
    


}