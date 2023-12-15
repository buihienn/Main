#include "UserInterface.h"

bool Trigger(double interval, double& lastUpdateTime) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

void GameOver(Game &game, bool gameOverButtonPressed) {
    if (game.GetGameOver()) {

        DrawText(TextFormat("GAME OVER"), 350, 200, 20, BLACK);

        // Ve nut retry
        Rectangle retryButton = { 350, 250, 100, 40 };
        DrawRectangleRec(retryButton, LIGHTGRAY);

        if (CheckCollisionPointRec(GetMousePosition(), retryButton)) {
            DrawRectangleLinesEx(retryButton, 2, RED);
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                // Xu ly khi nut Retry duoc bam
                game.SetGameOver(false);
                game.Reset();
                gameOverButtonPressed = true;
            }
        }
        else {
            DrawRectangleLinesEx(retryButton, 2, DARKGRAY);
        }
        DrawText("Retry", retryButton.x + 20, retryButton.y + 10, 20, DARKGRAY);
    }
    else {
        gameOverButtonPressed = false;
    }
}

void UserInterface(Game &game, double lastUpdateTime) {
    InitWindow(500, 710, "Tetris");
    SetTargetFPS(60);

    Color darkBlue = { 44, 44, 127, 255 };
    Color purple = { 128, 0, 128, 255 };
    bool gameOverButtonPressed = false;

    while (WindowShouldClose() == false) {
        game.HandleInput();
        UpdateMusicStream(game.music);

        if (Trigger(0.75, lastUpdateTime)) {
            game.MoveDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);

        ClearBackground(purple);

        DrawText(TextFormat("Score: %d", game.GetScore()), 320, 80, 20, RED);
        DrawText(TextFormat("NEXT "), 350, 150, 20, BLUE);

        GameOver(game, gameOverButtonPressed);
        
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}