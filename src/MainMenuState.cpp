#include "MainMenuState.h"

void MainMenuState::initBackground()
{
    this->background.setSize(sf::Vector2f
                             (
                              static_cast<float>(this->window->getSize().x),
                              static_cast<float>(this->window->getSize().y)
                              )
                             );
    if(!this->backgroundTexture.loadFromFile("splash.jpg"))
    {
        throw"ERROR EN CARGAR EL FONDO";
    }
    this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initVariables()
{


}

void MainMenuState::initKeybinds()
{
    std::ifstream ifs("mainmenustate_keybinds.conf");
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


void MainMenuState::initButtons() //recrear la funcion cada que necesitemos un boton
{
    this->buttons["GAME_STATE"]=new Button(304,67,120,50,&this->font,"Starting game",sf::Color::Red,sf::Color::Green,sf::Color::Blue);
    //ctor
    this->buttons["EXIT_STATE"]=new Button(514,67,120,50,&this->font,"Quit",sf::Color(70,70,70,200),sf::Color(150,150,150),sf::Color(20,20,20,200));
}


void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("sansation.ttf")){
        throw("No puedo cargar la fuente"); //cierra mi programa manda mensaje
    }
}


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys,std::stack<State*>* states)
    : State(window,supportedKeys,states) //inicializacion
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
}

MainMenuState::~MainMenuState()
{
    auto it= this->buttons.begin();
    for(it= this->buttons.begin();it!=this->buttons.end(); ++it )
    {

        delete it->second;
    }
    //dtor
}



void MainMenuState::updateInput(const float& dt)
{

    this->checkForEnd();

}



void MainMenuState::endState()
{
    std::cout<<"ending Game  main menu state!"<<"\n";
}

void MainMenuState::updateButtons()
{
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }

    if(this->buttons["GAME_STATE"]->isPressed())
    {
       this->states->push(new gameState(this->window, this->supportedKeys, this->states)); //puntero a pantalla supporte key y states
    }

    if(this->buttons["EXIT_STATE"]->isPressed())
    {
        this->quit=true;
    }


}



void MainMenuState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateButtons();
    //quit


}


void MainMenuState::renderButtons(sf::RenderTarget* target)
{
    for(auto &it : this->buttons)
    {
        it.second->render(target);
    }

}


void MainMenuState::render(sf::RenderTarget* target)
{
    if(!target)
        target=this->window;
    target->draw(this->background);
    //this->gameState_btn->render(target);
    this->renderButtons(target);
    /* mostrar texto en pantalla :3
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y -50);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(12);
    std::stringstream ss;
    ss<<this->mousePosView.x<<" "<<this->mousePosView.y;
    mouseText.setString(ss.str());
    target->draw(mouseText);*/

}

