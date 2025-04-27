//
// Created by Seif Khalifa on 08/02/2025.
#ifndef EXTRALIFE_H
#define EXTRALIFE_H

#include "PowerUp.h"
#include "../LivesManager.h"

class ExtraLife : public PowerUp {
private:
    float x, y;
    LivesManager* livesManager;

public:
    ExtraLife(float x, float y, LivesManager* livesManager);

    std::pair<float, float> getLocation() override;
    void execute() override;
    void setLocation(float x, float y) override;
};

#endif // EXTRALIFE_H