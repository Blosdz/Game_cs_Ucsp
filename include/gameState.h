#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <State.h>


class gameState : public State
{

    private:

    public:
        gameState(sf::RenderWindow* window);
        virtual ~gameState();
    //funciones
    void endState();
    void updateKeyBinds(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target=nullptr);
};

#endif // GAMESTATE_H
