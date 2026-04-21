#include <iostream>
#include <raylib.h>

#include "CoordinateSystem.h"

int main() {

    const int screen_width = 1280;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "Math Graph");
    SetWindowState(FLAG_WINDOW_ALWAYS_RUN);
    const float scale = 50.0f;
    const int step = 1;
    SetTargetFPS(1);

    CoordinateSystem coordinate_system = CoordinateSystem(screen_width, screen_height, scale,step);


    coordinate_system.DrawGrid();
    while(WindowShouldClose() == false) {
        BeginDrawing();

        coordinate_system.DrawGrid();


        EndDrawing();
    }


    return 0;
}
