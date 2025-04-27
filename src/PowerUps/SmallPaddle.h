//
// Created by Seif Khalifa on 27/04/2025.
//

#ifndef PONG_SMALLPADDLE_H
#define PONG_SMALLPADDLE_H

#include "PowerUp.h"
#include "../Paddle.h"

class SmallPaddle : public PowerUp {
private:
    float x, y;
    Paddle* paddle;

public:
    SmallPaddle(float x, float y, Paddle* paddle);

    std::pair<float, float> getLocation() override;
    void execute() override;
    void setLocation(float x, float y) override;
};


#endif //PONG_SMALLPADDLE_H
