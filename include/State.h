#ifndef STATE_H
#define STATE_H
#include<vector>
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<iostream>
#include<fstream> //open text file string and get the data
#include<sstream>

class State
{
private:
    std::vector<sf::Texture> textures;


public:
    State();
    virtual ~State();

    virtual void render()=0;
    virtual void update()=0; //funcion virtual necesitan ser determinadas
};

#endif // STATE_H
