#include "leftPanel.hpp"


void showLeftPanel(){

    static float width = GetScreenWidth()*0.2;
    static float height = GetScreenHeight();
    Rectangle leftPanelSize={0,0,width,height};
    GuiPanel(leftPanelSize,"");

    Rectangle labelSize={0,0,width,50};
    GuiPanel(labelSize,"");



}