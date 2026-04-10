#include <iostream>

#include "managers/App.h"

int main() {
    auto *gameManager = new App();

    if (!gameManager->HasInitialized()) {
        std::cout << "Failed to initialize game manager!" << std::endl;
        return 1;
    }

    gameManager->StartLoop();

    gameManager->Shutdown();
    return 0;
}


