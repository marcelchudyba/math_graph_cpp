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
    SetTargetFPS(60);

    CoordinateSystem coordinate_system = CoordinateSystem(screen_width, screen_height, scale,step);



    // coordinate_system.DrawGrid();

    // I ćwiartka (prawo, góra)
    coordinate_system.AddPoint(5, 5);

    // II ćwiartka (lewo, góra)
    coordinate_system.AddPoint(-5, 5);

    // III ćwiartka (lewo, dół)
    coordinate_system.AddPoint(-5, -5);

    // IV ćwiartka (prawo, dół)
    coordinate_system.AddPoint(5, -5);

    // Początek układu współrzędnych
    coordinate_system.AddPoint(0, 0);

  TraceLog(LOG_INFO, "Aktualna X to: %i", coordinate_system.points[0].GetX());
    TraceLog(LOG_INFO, "Aktualna Y to: %i", coordinate_system.points[0].GetY());

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

        coordinate_system.DrawCoordinateSystem();
        DrawText(TextFormat("x: %.0f y: %.0f", coordinate_system.origin.x ,coordinate_system.origin.y), 10, 50, 20, WHITE);

        EndDrawing();
    }


    return 0;
}
