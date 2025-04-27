//
// Created by Seif Khalifa on 27/04/2025.
//

#ifndef PONG_DURABLEBRICK_H
#define PONG_DURABLEBRICK_H
#include "Brick.h"

class DurableBrick : public Brick {
private:
    int health;

public:
    DurableBrick(float x, float y, float width, float height);

    bool onCollision() override;
    void draw() override;
};


#endif //PONG_DURABLEBRICK_H
