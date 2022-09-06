#pragma once

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State
{
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;

public:
    State(sf::RenderWindow* window);
    virtual ~State();

    //Close the state (probably just amounts to closing the game)
    virtual void endState() = 0;

    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};