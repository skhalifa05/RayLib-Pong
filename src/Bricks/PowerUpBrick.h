//
// Created by Seif Khalifa on 27/04/2025.
//

#ifndef PONG_POWERUPBRICK_H
#define PONG_POWERUPBRICK_H
#include "Brick.h"

class PowerUpBrick : public Brick {
public:
    PowerUpBrick(float x, float y, float width, float height);

    bool onCollision() override;
    void draw() override;
};


#endif //PONG_POWERUPBRICK_H
