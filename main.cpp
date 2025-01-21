#include "raylib.h"
#include <iostream>
#include "GameManager.h"

GameManager mGameManager;

int main() 
{
    InitWindow(1073, 1073, "Algorythm simulation");

    SetTargetFPS(60);

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