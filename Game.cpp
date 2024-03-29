#include "Game.hpp"

//Static functions

//Initialization functions

void Game::initWindow()
{
    //Window with a size of 200, 200
    //Will make options available in a text file

    std::ifstream ifs("Config/window.ini");

    std::string title = "none";
    sf::VideoMode window_bounds(800,600);
    unsigned framerate_limit = 60;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this -> window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys()
{
    std::ifstream ifs("Config/supportedKeys.ini");
    if (ifs.is_open())
    {
        std::string key = "";
        int keyValue = 0;
        while (ifs >> key >> keyValue)
        {
            this -> supportedKeys[key] = keyValue;
        }
    }
    ifs.close();
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this -> supportedKeys));
}

//Constructors / Destructors
//Constructor for creating the engine
Game::Game()
{
    //Creates the window
    this -> initWindow();
    this -> initKeys();
    this -> initStates();
}

//Destructor for closing the game
Game::~Game()
{
    //Deletes the game out of memory in order to not create a memory leak
    delete this -> window; 

    while(!this -> states.empty()){
        delete this -> states.top();
        this -> states.pop();
    }
}

/*
    Functions
*/
void Game::endApplication()
{
    std::cout << "Ending Application!\n";
}

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

void Game::update(const float& dt)
{
    this -> updateSFMLEvents();

        if (!this->states.empty())
        {
            this ->states.top()->update( this -> dt);

            if(this->states.top()->getQuit())
            {
                this->states.top()->endState();
                delete this-> states.top();
                this -> states.pop();
            }
        } 
        
        //Game end
        else 
        {   
            this -> endApplication();
            this -> window->close();
        }
}

void Game::render(sf::RenderTarget* target = nullptr)
{
    this -> window -> clear();

    //Render Items
    if (!this->states.empty()){
        this ->states.top()->render(this ->window);
    }

    this -> window -> display();
}

void Game::run()
{
    while (this-> window -> isOpen())
    {
        this -> updateDt();
        this -> update(this -> dt);
        this -> render();
    }

}