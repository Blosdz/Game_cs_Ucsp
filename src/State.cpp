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

void State::updateMousePositions()
{
    this->mousePosScreen=sf::Mouse::getPosition();
    this->mousePosWindow=sf::Mouse::getPosition(*this->window);
    this->mousePosView=this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}


void State::checkForEnd()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
    {
        this->quit=true;
    }

}
