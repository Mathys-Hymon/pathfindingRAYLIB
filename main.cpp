#include "raylib.h"
#include <iostream>
#include "GameManager.h"

GameManager mGameManager;

int main() 
{
    InitWindow(1024, 1024, "Algorythm simulation");

    SetTargetFPS(144);

	mGameManager.Load();

    while (!WindowShouldClose()) {

		mGameManager.Update();
        BeginDrawing();
        ClearBackground(DARKGREEN);
        mGameManager.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}