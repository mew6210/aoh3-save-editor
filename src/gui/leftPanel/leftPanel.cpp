#include "leftPanel.hpp"


void showLeftPanel(){

    static int width = GetScreenWidth()*0.2;

    Rectangle leftPanelSize={0,0,width,GetScreenHeight()};
    GuiPanel(leftPanelSize,"");

    Rectangle labelSize={0,0,width,50};
    GuiPanel(labelSize,"");



}