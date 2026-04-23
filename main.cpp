#include <iostream>
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

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
    char inputText[64] = "";
    bool editMode = false;

    TraceLog(LOG_INFO, "Aktualna X to: %i", coordinate_system.points[0].GetX());
    TraceLog(LOG_INFO, "Aktualna Y to: %i", coordinate_system.points[0].GetY());
    bool showMessageBox = false;
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
        if (GuiTextBox(Rectangle{ 10, 80, 150, 30 }, inputText, 64, editMode)) {
            editMode = !editMode;
        }


        if (GuiButton(Rectangle{ 170, 80, 100, 30 }, "Narysuj")) {

            TraceLog(LOG_INFO, "Przycisk zostal klikniety! Zawartosc inputa to: %s", inputText);



        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
