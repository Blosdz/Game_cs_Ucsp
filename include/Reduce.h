#ifndef REDUCE_H
#define REDUCE_H
#include"State.h"
class Reduce
{

    private:
        sf::RenderWindow* window;
        sf::Event sfEvent;
        void initWindow();


        sf::Clock dtClock;

        float dt; //delta time

    public:
        Reduce();
        virtual ~Reduce();
        void updateSFMLEvents();
        void update();
        void render();
        void run();
        void updateDt();

};

#endif // REDUCE_H
