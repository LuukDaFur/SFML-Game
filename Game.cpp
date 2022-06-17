#include "Game.hpp"

//Static functions

//Initialization functions

void Game::initWindow()
{
    //Window with a size of 200, 200
    //Will make options available in a text file
    this -> window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

//Constructors / Destructors
//Constructor for creating the engine
Game::Game()
{
    //Creates the window
    this -> initWindow();
}

//Destructor for closing the game
Game::~Game()
{
    //Deletes the game out of memory in order to not create a memory leak
    delete this -> window; 
}

//Functions
void Game::updateDt()
{
    /*
        Updates the DeltaTime Variable (dt) with the time it took to update and render one frame
    */
    this -> dt = this -> dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
        while (this -> window -> pollEvent(this -> sfEvent))
        {
            if (this -> sfEvent.type == sf::Event::Closed){
                this -> window -> close();
        }
    }
}

void Game::update()
{
    this -> updateSFMLEvents();
}

void Game::render()
{
    this -> window -> clear();

    //Render Items

    this -> window -> display();
}

void Game::run()
{
        while (this -> window -> isOpen())
    {
        this -> updateDt();
        this -> update();
        this -> render();
    }

}