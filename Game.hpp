#pragma once

#include "State.hpp"

class Game
{   
    private:
        //Variables
        sf::RenderWindow *window;
        sf::Event sfEvent;

        sf::Clock dtClock;
        float dt;

        //Initialization functions
        void initWindow();

    public:
        //Constructor / Destructor
        Game();
        virtual ~Game();

        //Functions
        void updateDt();
        void updateSFMLEvents();
        void update();
        void render();
        void run();
};