#include <iostream>
#include <raylib.h>
#include <string>

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

    char x[64] = "";
    char y[64] = "";

    bool editMode = false;
    bool editMode2 = false;

    float left_distance = 0.0f;
    float right_distance = 0.0f;



    TraceLog(LOG_INFO, "Aktualna X to: %i", coordinate_system.points[0].GetX());
    TraceLog(LOG_INFO, "Aktualna Y to: %i", coordinate_system.points[0].GetY());
    bool showMessageBox = false;
    while(WindowShouldClose() == false) {

        BeginDrawing();

        ClearBackground(RAYWHITE);
        // if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        //     left_distance = 0.0f;
        //     right_distance = 0.0f;
        // }


        // Sprawdzanie, czy lewy przycisk myszy jest TRZYMANY
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {

            Vector2 delta = GetMouseDelta();
            coordinate_system.origin.x += delta.x;
            coordinate_system.origin.y += delta.y;

            SetMouseCursor(MOUSE_CURSOR_RESIZE_ALL);
        } else {
            SetMouseCursor(DEFAULT);
        }

        ClearBackground(BLACK);

        //powiekszanie i zmniejszanie
        float wheelMove = GetMouseWheelMove();
        if (wheelMove != 0.0f) {

            scale += wheelMove * 5;
            if (scale < 5) {
                scale = 5;
            }
            coordinate_system.UpdateScale(scale);
        }



        coordinate_system.DrawCoordinateSystem();


        //Gui
        DrawText(TextFormat("x: %.0f y: %.0f", coordinate_system.origin.x ,coordinate_system.origin.y), 10, 50, 20, WHITE);
        if (GuiTextBox(Rectangle{ 10, 80, 150, 30 }, x, 64, editMode)) {
            editMode = !editMode;
        }
        if (GuiTextBox(Rectangle{ 10, 130, 150, 30 }, y, 64, editMode2)) {
            editMode2 = !editMode2;
        }
        if (GuiButton(Rectangle{ 170, 80, 100, 30 }, "Narysuj")) {
            TraceLog(LOG_INFO, "Przycisk zostal klikniety! Zawartosc inputa to: %s", x);
            coordinate_system.AddPoint(std::stoi(x), std::stoi(y));
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
