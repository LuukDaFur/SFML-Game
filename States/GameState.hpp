#pragma once

#include "State.hpp"

class GameState :
    public State
{
    private:
        Entity player;

    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();

    //functions
    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};