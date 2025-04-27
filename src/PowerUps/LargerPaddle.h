//
// Created by Seif Khalifa on 08/02/2025.
//

#ifndef LARGERPADDLE_H
#define LARGERPADDLE_H

#include "PowerUp.h"
#include "../Paddle.h"

class LargerPaddle : public PowerUp {
private:
    float x, y;
    Paddle* paddle;

public:
    LargerPaddle(float x, float y, Paddle* paddle);

    std::pair<float, float> getLocation() override;
    void execute() override;
    void setLocation(float x, float y) override;
};

#endif // LARGERPADDLE_H
