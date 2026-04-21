#include <iostream>
#include <raylib.h>

#include "CoordinateSystem.h"

int main() {

    const int screen_width = 1280;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "Math Graph");
    SetWindowState(FLAG_WINDOW_ALWAYS_RUN);
     float scale = 20.0f;
    const int step = 1;
    SetTargetFPS(24);

    CoordinateSystem coordinate_system = CoordinateSystem(screen_width, screen_height, scale,step);



    coordinate_system.DrawGrid();
    while(WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(BLACK);
        float wheelMove = GetMouseWheelMove();
        if (wheelMove != 0.0f) {

            scale += wheelMove * 5;


            if (scale < 5) {
                scale = 5;
            }
            coordinate_system.UpdateScale(scale);
        }

        coordinate_system.DrawGrid();


        EndDrawing();
    }


    return 0;
}
