#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <gameState.h>
#include"Button.h"

class MainMenuState : public State
{

    private:
        //variables
        sf::Texture backgroundTexture;
        sf::RectangleShape background;
        //funciones
        sf::Font font;
        /*Button* gameState_btn;*/
        std::map<std::string, Button*> buttons;
        void initBackground();
        void initVariables();
        void initFonts();
        void initButtons();
        void initKeybinds();
    public:
        MainMenuState(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys,std::stack<State*>* states);
        virtual ~MainMenuState();
    //funciones
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void updateButtons();
    void renderButtons(sf::RenderTarget* target=nullptr);
    void render(sf::RenderTarget* target=nullptr);

};

#endif // MAINMENUSTATE_H
