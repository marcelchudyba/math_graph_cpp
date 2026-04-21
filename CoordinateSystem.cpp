//
// Created by XXX on 21.04.2026.
//

#include "CoordinateSystem.h"
CoordinateSystem::CoordinateSystem(int screen_width, int screen_height, float scale,int gridStep) :
    screen_width(screen_width), screen_height(screen_height), scale(scale),gridStep(gridStep){};

void CoordinateSystem::DrawStep(int x, int y,int text_x, int text_y, int value, bool direction) {
        if(direction) {
            DrawLine(x, y - scale / 4, x,y + scale / 4, WHITE);
        }
        else {
            DrawLine(x - scale / 4, y, x + scale / 4,y, WHITE);
        }
        DrawText(TextFormat("%i", value), x + text_x, y + text_y,scale / 2,  WHITE);
}

void CoordinateSystem::UpdateScale(int new_value) {
    scale = new_value;
}


void CoordinateSystem::DrawGrid() {

        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);

        DrawLine(0, screen_height / 2,screen_width , screen_height / 2, WHITE);
        int step = 0;
        for(int i = screen_width / 2; i < screen_width; i+= scale) {
            DrawStep(i, screen_height / 2,0, 15, step,true);
            step += gridStep;
        }
        step = gridStep;
        for(int i = screen_width / 2 + scale; i > 0; i-= scale) {
            DrawStep(i, screen_height / 2,0, 15, step,true);
            step -= gridStep;
        }
        step = 0;
        for(int i = screen_height / 2; i < screen_height; i+= scale) {
            DrawStep(screen_width / 2, i,15, 0, step,false);
            step -= gridStep;
        }
        step = gridStep;
         for(int i = screen_height / 2 - scale; i > 0; i-= scale) {
            DrawStep(screen_width / 2, i,15, 0, step,false);
            step += gridStep;
         }
}


