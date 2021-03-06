#ifndef STATE_H
#define STATE_H
#include"Entity.h"

class State
{
private:
    //resources
protected:
    std::stack<State*>* states; //puntero de stack que apunta al stack de punteros. .S
    sf::RenderWindow* window;
    std::map<std::string,int>* supportedKeys;
    std::map<std::string,int> keybinds;
    bool quit;
    //resources ??
    std::vector<sf::Texture> textures;
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    virtual void initKeybinds()=0;
public:
    State(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys,std::stack<State*>* states );
    virtual ~State();


    const bool& getQuit() const;
    virtual void checkForEnd();
    virtual void endState()=0;
    virtual void updateMousePositions();
    virtual void updateInput(const float& dt)=0;
    virtual void update(const float& dt)=0; //funcion virtual necesitan ser determinadas
    virtual void render(sf::RenderTarget* target=nullptr)=0;
};

#endif // STATE_H
