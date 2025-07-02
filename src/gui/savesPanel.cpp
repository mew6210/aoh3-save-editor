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
    static Rectangle bounds={
        0,
        0,
        static_cast<float>(windowWidth*0.3),
        static_cast<float>(windowHeight)};
    static Rectangle scrollBounds={
        0,
        0,
        static_cast<float>((windowWidth*0.3)-15),
        static_cast<float>(windowHeight+(saves.size()*saveHeight))};



    GuiScrollPanel(bounds,"Saves",scrollBounds,&scroll,&panelView);

        


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