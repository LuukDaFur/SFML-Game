#pragma once

#include "../Entities/Entity.hpp"

class State
{
private:
    std::vector<sf::Texture> textures;
    bool quit;

protected:
    sf::RenderWindow* window;

public:
    State(sf::RenderWindow* window);
    virtual ~State();

    const bool& getQuit() const;

    //Close the state (probably just amounts to closing the game)
    virtual void checkForQuit();

    virtual void endState() = 0;
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};