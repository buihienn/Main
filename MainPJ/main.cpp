#include "UserInterface.h"

int main() {
    srand(time(NULL));
    
    Game game;
    double lastUpdateTime = GetTime();

    UserInterface(game, lastUpdateTime);

    return 0;
}
