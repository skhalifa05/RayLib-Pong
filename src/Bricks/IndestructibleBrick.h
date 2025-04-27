//
// Created by Seif Khalifa on 27/04/2025.
//

#ifndef PONG_INDESTRUCTIBLEBRICK_H
#define PONG_INDESTRUCTIBLEBRICK_H
#include "Brick.h"

class IndestructibleBrick : public Brick {
public:
    IndestructibleBrick(float x, float y, float width, float height);

    bool onCollision() override;
    void draw() override;
};


#endif //PONG_INDESTRUCTIBLEBRICK_H
