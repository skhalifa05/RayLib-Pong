//
// Created by Seif Khalifa on 08/02/2025.
//

#ifndef LIVESMANAGER_H
#define LIVESMANAGER_H



class LivesManager {
    private:
        int lives = 0;
        const int distancebetweenLives = 20;
    public:
        LivesManager(int lives);
        void loseLife();
        void draw();
        bool dead();
};



#endif //LIVESMANAGER_H
