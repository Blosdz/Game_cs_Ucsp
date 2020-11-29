#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <State.h>


class gameState : public State
{

    private:
        Entity player;
        //funciones
        void initKeybinds();
    public:
        gameState(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys);
        virtual ~gameState();
    //funciones
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target=nullptr);
};

#endif // GAMESTATE_H
