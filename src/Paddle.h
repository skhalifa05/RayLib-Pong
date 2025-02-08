//
// Created by Seif Khalifa on 06/02/2025.
//

#ifndef PADDLE_H
#define PADDLE_H
#include <utility>

using namespace std;

class Paddle {
    public:
        Paddle(float center, float yCoordinates, float paddleSpeed,  float width, float height);
        void update();
        void draw();
        pair<float, float> getLocation();

    private:
        float x, y, paddleSpeed, width, height;

};



#endif //PADDLE_H
