#include <SFML/Graphics.hpp>
#include<iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 600), "The zelda",sf::Style::Close|sf::Style::Titlebar);
    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
*/
    sf::VideoMode::getDesktopMode();
    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt)) /*evnt lo llamo en vez de evento por posible problemas con las palabras reservadas | además este evento me ayuda a cerrar el programa*/
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        /*window.draw(shape);*/
        window.display();
    }

    return 0;
}