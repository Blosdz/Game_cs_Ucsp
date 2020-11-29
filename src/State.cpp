#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys)
{
    //ctor
    this->window=window;
    this->supportedKeys=supportedKeys;
    this->quit=false;
}

State::~State()
{
    //dtor
}

//const
const bool & State::getQuit()const
{
    return this->quit;

}

void State::checkForEnd()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit=true;
    }

}
