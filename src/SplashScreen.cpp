#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow  renderWindow)
{
    sf::Texture pTexture;
    sf::Sprite image;
    if(!pTexture.loadFromFile("splash.jpg"))
        std::cout<<"error"<<std::endl;
    image.setTexture(pTexture);

    renderWindow.draw(image);
    renderWindow.display();
    sf::Event event;
    while(true)
    {
        while(renderWindow.waitEvent(event))
        {
            if(event.type==sf::Event::EventType::KeyPressed || event.type==sf::Event::EventType::MouseButtonPressed){
                return;
            }
        }
    }
}
SplashScreen::SplashScreen()
{
    //ctor
}

SplashScreen::~SplashScreen()
{
    //dtor
}
