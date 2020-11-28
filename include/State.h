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
#include<stack>
#include<map>
#include<vector>


class State
{
private:
    //resources
    std::vector<sf::Texture> textures;
    sf::RenderWindow* window;
    bool quit;

public:
    State(sf::RenderWindow* window);
    virtual ~State();


    const bool& getQuit() const;
    virtual void checkForEnd();
    virtual void endState()=0;
    virtual void updateKeyBinds(const float& dt)=0;
    virtual void update(const float& dt)=0; //funcion virtual necesitan ser determinadas
    virtual void render(sf::RenderTarget* target=nullptr)=0;
};

#endif // STATE_H
