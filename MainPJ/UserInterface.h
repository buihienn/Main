#pragma once
#include <raylib.h>
#include "game.h"
#include "time.h"


bool Trigger(double interval, double& lastUpdateTime);
void UserInterface(Game &game, double lastUpdateTime);
void GameOver(Game &game, bool gameOverButtonPressed);
