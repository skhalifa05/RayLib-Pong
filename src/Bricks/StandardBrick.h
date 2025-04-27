//
// Created by Seif Khalifa on 27/04/2025.
//

#ifndef PONG_STANDARDBRICK_H
#define PONG_STANDARDBRICK_H
#include "Brick.h"

class StandardBrick : public Brick {
public:
    StandardBrick(float x, float y, float width, float height);

    void draw() override;
};


#endif //PONG_STANDARDBRICK_H
