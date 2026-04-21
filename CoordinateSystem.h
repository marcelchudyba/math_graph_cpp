//
// Created by XXX on 21.04.2026.
//

#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H
#include <raylib.h>


class CoordinateSystem {
public:
    Vector2 origin;
    int screen_width,screen_height,gridStep;
    float scale;
    CoordinateSystem(int screen_width, int screen_height,float scale,int gridStep);
    void DrawGrid();
    void DrawStep(int x, int y,int text_x, int text_y, int value,bool direction);
    void DrawPoint(Vector2 point);
    void UpdateScale(int new_value);
    Vector2 GetCenter();
};



#endif //COORDINATESYSTEM_H
