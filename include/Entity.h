#ifndef ENTITY_H
#define ENTITY_H

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


class Entity
{
    protected:
        sf::RectangleShape shape;
        float movementSpeed;

    public:
        Entity();
        virtual ~Entity();
        //entity funciones
        virtual void move(const float& dt, float x, const float y);
        virtual void update(const float& dt);
        virtual void render(sf::RenderTarget* target);
};

#endif // ENTITY_H
