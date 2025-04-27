//
// Created by Seif Khalifa on 08/02/2025.
//

#ifndef POWERUP_H
#define POWERUP_H
#include <utility>  // For std::pair

class PowerUp {
public:
    virtual ~PowerUp() = default;

    // Returns the location of the power-up
    virtual std::pair<float, float> getLocation() = 0;

    // Executes the power-up effect
    virtual void execute() = 0;

    virtual void setLocation(float x, float y) = 0;
};
#endif //POWERUP_H
