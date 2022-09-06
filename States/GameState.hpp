#pragma once

#include "State.hpp"

class GameState :
    public State
{
    private:

    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();

    //functions
    void endState();


    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};