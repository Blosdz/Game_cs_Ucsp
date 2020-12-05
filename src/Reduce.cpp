#include "Reduce.h"
#include<SFML/Graphics.hpp>
#include<iostream>


void Reduce::initWindow()
{
    std::ifstream ifs("window.conf");
    std::string title="theZelda";
    sf::VideoMode window_bounds(800,600);
    unsigned framerate_limit=120;
    bool vertica_sync_enable=false;
    if(ifs.is_open())
    {
        std::getline(ifs,title);
        ifs>>window_bounds.width>>window_bounds.height;
        ifs>>framerate_limit;
        ifs>>vertica_sync_enable;
    }
    ifs.close();
    this->window=new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertica_sync_enable);
}

void Reduce::initKeys()
{
    std::ifstream ifs("supported_keys.conf");
    if(ifs.is_open())
    {
        std::string key="";
        int key_value=0;
        while(ifs>>key>>key_value){
            this->supportedKeys[key]=key_value;
        }
    }
    ifs.close();
    //QUITAR ESTO WANDO TENGA TIEMPO
    for(auto i :this->supportedKeys)
    {
        std::cout<<i.first<<" "<<i.second<<"\n";
    }


}

void Reduce::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys,&this->states));
}
Reduce::Reduce()
{
    this->initWindow();
    this->initKeys();
    this->initStates();
    //ctor
}

Reduce::~Reduce()
{
    delete this->window;
    //dtor
    while(!this->states.empty()){
        delete this->states.top(); //eliminando para no usar mas memoria
        this->states.pop();
    }
}

void Reduce::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }

}

void Reduce::update()
{

    this->updateSFMLEvents();

    if(!this->states.empty()){
        this->states.top()->update(this->dt);
        if(this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else{
        this->endAplication();
        this->window->close();
    }
}

void Reduce::render()
{

    this->window->clear();
    //
    if(!this->states.empty()){
        this->states.top()->render(this->window);
    }
    this->window->display();
}

void Reduce::endAplication()
{
    std::cout<<"end application"<<"\n";
}
void Reduce::updateDt()
{
    /*renueeva el reloj para delta tiempo que nos demora renderizar un frame*/
    this->dt=this->dtClock.restart().asSeconds();


}

void Reduce::run()
{

    while (this->window->isOpen())
    {
        this->updateDt(); //reset clock
        this->update();
        this->render();
    }

}
