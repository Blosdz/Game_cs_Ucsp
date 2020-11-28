#ifndef REDUCE_H
#define REDUCE_H
#include"gameState.h"

class Reduce
{

    private:
        sf::RenderWindow* window;
        sf::Event sfEvent;
        void initWindow();
        //states
        void initStates();

        sf::Clock dtClock;

        float dt; //delta time
        std::stack<State*> states; //object class no se puede crear objs solo referencias 0
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
