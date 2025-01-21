#include "raylib.h"
#include <iostream>

using namespace std;

int main() {

    
    cout << "Hello World" << endl;

    InitWindow(1100, 1100, "Algorythm simulation");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}