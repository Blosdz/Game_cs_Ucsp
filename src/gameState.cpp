#include "gameState.h"

gameState::gameState(sf::RenderWindow* window)
    : State(window)
{
    //ctor
}

gameState::~gameState()
{
    //dtor
}


void gameState::updateKeyBinds(const float& dt)
{
    this->checkForEnd();

}

void gameState::update(const float& dt)
{
    this->updateKeyBinds(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        std::cout<<"A"<<"\n";

}


void gameState::render(sf::RenderTarget* target)
{


}

void gameState::endState()
{
    std::cout<<"ending Game state!"<<"\n";
}
