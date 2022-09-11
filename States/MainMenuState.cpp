#include "./MainMenuState.hpp"

void MainMenuState::initKeybinds()
{
    std::ifstream ifs("Config/MainMenu_Controls.ini");
    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";
        while (ifs >> key >> key2)
        {
            this -> keybinds[key] = this -> supportedKeys -> at(key2);
        }
    }
    ifs.close();

    for (auto i : this -> keybinds)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
}

void MainMenuState::initFonts()
{
    if(!this -> mainMenuFont.loadFromFile("Fonts/FiraSans-MediumItalic.ttf"))
    {
        throw("ERROR: MAIN_MENU_STATE  COULD NOT LOAD FONT");
    }
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
    : State(window, supportedKeys)
{
    this -> initFonts();
    this -> initKeybinds();

    this -> gameStateButton = new Button(100, 100, 150, 50, 
    &this-> mainMenuFont, "New Game", 
    sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

    this -> background.setSize(sf::Vector2f(window -> getSize().x, (float)window -> getSize().y));
    this -> background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
    delete this-> gameStateButton;
}

void MainMenuState::endState()
{
    std::cout << "Ending Game State\n";
}

void MainMenuState::updateInput(const float& dt)
{
    this -> checkForQuit();


    
}

void MainMenuState::update(const float& dt)
{
    this-> updateMousePositions();
    this-> updateInput(dt);

    this-> gameStateButton->update(mousePosView);
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if(!target)
    {
        target = this -> window;
    }

    target -> draw(this -> background);
    this-> gameStateButton -> render(target);
}