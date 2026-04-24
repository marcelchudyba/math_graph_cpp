//
// Created by XXX on 21.04.2026.
//

#include "CoordinateSystem.h"

#include "Point.h"

CoordinateSystem::CoordinateSystem(int screen_width, int screen_height, float scale,int gridStep) :
    screen_width(screen_width), screen_height(screen_height), scale(scale),gridStep(gridStep) {
    GetCenter();
};

void CoordinateSystem::DrawStep(int x, int y,int text_x, int text_y, int value, bool direction) {
        //direction == true points at steps on OX

        if(direction) {
            if(x != origin.x) DrawLine(x, 0, x,screen_height, GRAY);
            // DrawLine(x, y - scale / 4, x,y + scale / 4, WHITE);

        }
        else {
           if(y != origin.y) DrawLine(0, y, screen_width,y, GRAY);

            // DrawLine(x - scale / 4, y, x + scale / 4,y, WHITE);
        }


        int text_xx;

        if(x < 30 && y != origin.y)
            text_xx = 30 + text_x;
        else if(x > screen_width && y != origin.y)
            text_xx = screen_width + text_x ;
        else
            text_xx = x + text_x;

        int text_yy;

        if(y < 0 && x != origin.x)
            text_yy = text_y;
        else if(y > screen_height - 35 && x != origin.x)
            text_yy = screen_height - 35 + text_y;
        else
            text_yy = y + text_y;



        DrawText(TextFormat("%i", value), text_xx, text_yy,15,  WHITE);
}

void CoordinateSystem::UpdateScale(int new_value) {
    scale = new_value;
}


void CoordinateSystem::DrawGrid() {

        int center_of_grid_x = origin.x;
        int center_of_grid_y = origin.y;

        DrawLine(center_of_grid_x, 0, center_of_grid_x, screen_height, RED);

        DrawLine(0, center_of_grid_y,screen_width , center_of_grid_y, RED);
        int step = 0;
        for(int i = center_of_grid_x; i < screen_width; i+= scale) {
            DrawStep(i, center_of_grid_y,-3, 15, step,true);
            step += gridStep;
        }
        step = gridStep;
        for(int i = center_of_grid_x + scale; i > 0; i-= scale) {
            DrawStep(i, center_of_grid_y,-11, 15, step,true);
            step -= gridStep;
        }
        step = 0;
        for(int i = center_of_grid_y; i < screen_height; i+= scale) {
            DrawStep(center_of_grid_x, i,-20, -8, step,false);
            step -= gridStep;
        }
        step = gridStep;
         for(int i = center_of_grid_y - scale; i > 0; i-= scale) {
            DrawStep(center_of_grid_x, i,-20, -8, step,false);
            step += gridStep;
         }

}

void CoordinateSystem::GetCenter() {
    int x = screen_width / 2;
    int y = screen_height / 2;

    origin.x = x;
    origin.y = y;
}

Vector2 CoordinateSystem::ConvertXY(int x, int y) {
    int screen_x = origin.x + (x * scale);
    int screen_y = origin.y - (y * scale);

    return Vector2(screen_x,screen_y);
}


void CoordinateSystem::AddPoint(int x, int y) {

    points.push_back(Point(x,y));
}


void CoordinateSystem::DrawPoint(Point point) {
    Vector2 converted_point = ConvertXY(point.GetX(),point.GetY());

    float radius = scale / 10.0f;

    if (radius < 3.0f) radius = 3.0f;

    DrawCircle(converted_point.x, converted_point.y, radius, WHITE);
}
void CoordinateSystem::DrawPoints(std::vector<Point>& points) {
    for (Point &point : points) {
        DrawPoint(point);
    }
}


void CoordinateSystem::DrawCoordinateSystem() {
    DrawGrid();
    DrawPoints(points);
}


