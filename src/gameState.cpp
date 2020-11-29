#include "gameState.h"

gameState::gameState(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys)
    : State(window,supportedKeys) //inicializacion
{
    this->initKeybinds();
    //ctor
}

gameState::~gameState()
{
    //dtor
}

void gameState::initKeybinds()
{
    this->keybinds.emplace("MOVE_LEFT",this->supportedKeys->at("A")); //funcion creada que usara la palabra A que es base del engine sfml
    this->keybinds.emplace("MOVE_RIGHT",this->supportedKeys->at("D"));
    this->keybinds.emplace("MOVE_UP",this->supportedKeys->at("W"));
    this->keybinds.emplace("MOVE_DOWN",this->supportedKeys->at("S"));
}

void gameState::updateInput(const float& dt)
{

    this->checkForEnd();
    //update player input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player.move(dt,-1.f,0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player.move(dt,1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player.move(dt,0.f,-1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player.move(dt,0.f,1.f);

}

void gameState::update(const float& dt)
{
    this->updateInput(dt);
    this->player.update(dt);


}


void gameState::render(sf::RenderTarget* target)
{
    if(!target)
        target=this->window;
    this->player.render(target);

}

void gameState::endState()
{
    std::cout<<"ending Game state!"<<"\n";
}
