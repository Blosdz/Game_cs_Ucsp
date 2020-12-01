#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys)
    : State(window,supportedKeys) //inicializacion
{
    this->initFonts();
    this->initKeybinds();

    this->gameState_btn=new Button(70,70,70,50,&this->font,"Starting game",sf::Color::Red,sf::Color::Green,sf::Color::Blue);
    //ctor
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
    delete this->gameState_btn;
    //dtor
}


void MainMenuState::updateInput(const float& dt)
{

    this->checkForEnd();

}

void MainMenuState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);
    this->gameState_btn->update(this->mousePosView);

}
void MainMenuState::initKeybinds()
{
    std::ifstream ifs("gamestate_keybinds.conf");
    if(ifs.is_open())
    {
        std::string key="";
        std::string key2="";
        while(ifs>>key>>key2){
            this->keybinds[key]=this->supportedKeys->at(key2);
        }
    }
    ifs.close();
/*
    this->keybinds["CLOSE"]=this->supportedKeys->at("ESCAPE");
    this->keybinds["MOVE_LEFT"]=this->supportedKeys->at("A"); //funcion creada que usara la palabra A que es base del engine sfml
    this->keybinds["MOVE_RIGHT"]=this->supportedKeys->at("D");
    this->keybinds["MOVE_UP"]=this->supportedKeys->at("W");
    this->keybinds["MOVE_DOWN"]=this->supportedKeys->at("S");
*/
}

void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("sansation.ttf")){
        throw("No puedo cargar la fuente"); //cierra mi programa manda mensaje
    }
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if(!target)
        target=this->window;
    target->draw(this->background);
    this->gameState_btn->render(target);
}

void MainMenuState::endState()
{
    std::cout<<"ending Game state!"<<"\n";
}
