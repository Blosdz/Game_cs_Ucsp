#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include"State.h"
#include <iostream>

class SplashScreen
{
    public:
        void Show(sf::RenderWindow window);
        SplashScreen();
        virtual ~SplashScreen();

    protected:

    private:
};

#endif // SPLASHSCREEN_H
