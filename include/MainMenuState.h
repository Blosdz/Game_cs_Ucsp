#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <gameState.h>
#include"Button.h"

class MainMenuState : public State
{

    private:
        //variables
        sf::RectangleShape background;
        //funciones
        sf::Font font;
        Button* gameState_btn;
        void initFonts();
        void initKeybinds();
    public:
        MainMenuState(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys);
        virtual ~MainMenuState();
    //funciones
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target=nullptr);

};

#endif // MAINMENUSTATE_H
