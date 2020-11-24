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

Reduce::Reduce()
{
    this->initWindow();
    //ctor
}

Reduce::~Reduce()
{
    delete this->window;
    //dtor
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
}

void Reduce::render()
{

    this->window->clear();
    this->window->display();
}


void Reduce::updateDt()
{
    /*renueeva el reloj para delta tiempo que nos demora renderizar un frame*/
    this->dt=this->dtClock.getElapsedTime().asSeconds();


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

