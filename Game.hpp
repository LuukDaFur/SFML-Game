#pragma once

#include "States/GameState.hpp"

class Game
{   
    private:
        //Variables
        sf::RenderWindow *window;
        sf::Event sfEvent;

        sf::Clock dtClock;
        float dt;

        std::stack<State*> states;

        std::map<std::string, int> supportedKeys;

        //Initialization functions
        void initWindow();
        void initKeys();
        void initStates();

    public:
        //Constructor / Destructor
        Game();
        virtual ~Game();

        //Functions

        //regular
        void endApplication();

        //update        
        void updateDt();
        void updateSFMLEvents();
        void update(const float& dt);
        
        //render
        void render(sf::RenderTarget* target);
        
        //core
        void run();
};