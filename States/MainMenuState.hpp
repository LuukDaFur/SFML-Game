#pragma once

#include "./GameState.hpp"
#include "./State.hpp"
#include "../Resources/Button.hpp"

class MainMenuState :
    public State
{
    private:
        //Variables
        sf::RectangleShape background;
        sf::Font mainMenuFont;

        Button* gameStateButton;

        //functions
        void initKeybinds();
        void initFonts();
        
    public:
        MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
        virtual ~MainMenuState();

    //functions
    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};