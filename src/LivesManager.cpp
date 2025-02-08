//
// Created by Seif Khalifa on 08/02/2025.
//

#include "LivesManager.h"

#include <../include/raylib.h>

LivesManager::LivesManager(int lives) {
    this->lives = lives;
}

void LivesManager::loseLife() {
    this->lives--;
}

void LivesManager::draw() {
    for (int i = 1; i<= this->lives; i++) {
        DrawCircle(GetScreenWidth() - (distancebetweenLives*i), distancebetweenLives,5,RED);
    }
}

bool LivesManager::dead() {
    return lives == 0;
}

