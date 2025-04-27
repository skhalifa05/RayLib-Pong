//
// Created by Seif Khalifa on 27/04/2025.
//

#ifndef PONG_BRICK_H
#define PONG_BRICK_H
#include <raylib.h>

class Brick {
protected:
    float x, y;
    float width, height;
    bool destroyed = false;

public:
    Brick(float x, float y, float width, float height);

    virtual void update();
    virtual void draw();
    virtual bool onCollision();

    float GetX();
    float GetY();
    bool isDestroyed() const;
    Rectangle getRect() const;
};

#endif //PONG_BRICK_H
