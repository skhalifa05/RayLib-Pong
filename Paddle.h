//
// Created by Seif Khalifa on 06/02/2025.
//

#ifndef PADDLE_H
#define PADDLE_H
#include <utility>

using namespace std;

class Paddle {
    public:
        Paddle(float center);
        void update();
        void draw();
        pair<float, float> getLocation();

    private:
        float x, y;

};



#endif //PADDLE_H
