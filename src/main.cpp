#include <SFML/Graphics.hpp>
#include<iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 600), "The zelda",sf::Style::Close|sf::Style::Titlebar);
    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
*/  
    window.setFramerateLimit(60);
    sf::RectangleShape rectangle(sf::Vector2f(100.0f,100.0f));
    rectangle.setFillColor(sf::Color::Blue);

    rectangle.setPosition(440,300);

    sf::VideoMode::getDesktopMode();
    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt)) /*evnt lo llamo en vez de evento por posible problemas con las palabras reservadas | además este evento me ayuda a cerrar el programa*/
        {
            if (evnt.type == sf::Event::Closed)
                window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

                rectangle.move(0,5);
            }
        }

        window.clear();
        /*window.draw(shape);*/
        window.draw(rectangle);
        window.display();
    }

    return 0;
}