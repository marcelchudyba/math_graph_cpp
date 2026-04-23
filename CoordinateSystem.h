//
// Created by XXX on 21.04.2026.
//

#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H
#include <raylib.h>
#include <vector>

#include "Point.h"


class CoordinateSystem {
public:
    std::vector<Point> points;
    Vector2 origin;
    int screen_width,screen_height,gridStep;
    float scale;
    CoordinateSystem(int screen_width, int screen_height,float scale,int gridStep);
    void DrawGrid();
    void DrawCoordinateSystem();
    void DrawStep(int x, int y,int text_x, int text_y, int value,bool direction);
    void AddPoint(int x, int y);
    void DrawPoint(Point point);
    void DrawPoints(std::vector<Point> points);
    void UpdateScale(int new_value);
    void GetCenter();
    Vector2 ConvertXY(int x, int y);

};



#endif //COORDINATESYSTEM_H
