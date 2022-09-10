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

        //Initialization functions
        void initWindow();
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