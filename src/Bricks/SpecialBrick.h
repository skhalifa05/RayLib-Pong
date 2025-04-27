//
// Created by Seif Khalifa on 27/04/2025.
//

#ifndef PONG_SPECIALBRICK_H
#define PONG_SPECIALBRICK_H
#include "Brick.h"

class SpecialBrick : public Brick {
public:
    SpecialBrick(float x, float y, float width, float height);

    bool onCollision() override;
    void draw() override;
};


#endif //PONG_SPECIALBRICK_H
