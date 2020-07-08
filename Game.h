#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Game
{
private:
	//variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> VideoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;

	//Initialization
	void initVariables();
	void initWindow();
	void initStates();
	void initKeys();

public:
	//Constructors /Destructors
	Game();
	virtual ~Game();

	//Functions

	//Regular
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//render
	void render();

	//Core
	void run();
};

#endif