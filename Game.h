#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Game
{
private:
	class GraphicsSettings {
	public:
		GraphicsSettings()
		{
			this->title = "UNINIZIALIZED";
			this->resolution = sf::VideoMode::getDesktopMode();
			this->fullscreen = false;
			this->verticalSync = false;
			this->frameRateLimit = 120;
			this->contextSettings.antialiasingLevel = 0;
			this->videoModes = sf::VideoMode::getFullscreenModes();
		
		}
		//Variables
		std::string title;
		sf::VideoMode resolution;
		bool fullscreen;
		bool verticalSync;
		unsigned frameRateLimit;
		sf::ContextSettings contextSettings;
		std::vector<sf::VideoMode> videoModes;

		//Functions
		void saveToFile(const std::string path)
		{
			std::ofstream ofs(path);

			if (ofs.is_open()) {
				ofs << this->title;
				ofs << this->resolution.width << " " << this->resolution.height;
				ofs << this->fullscreen;
				ofs << this->frameRateLimit;
				ofs << this->verticalSync;
				ofs << this->contextSettings.antialiasingLevel;
			}
			ofs.close();
		}

		void loadFromFile(const std::string path)
		{
			std::ifstream ifs(path);

			if (ifs.is_open()) {
				std::getline(ifs, title);
				ifs >> this->resolution.width >> this->resolution.height;
				ifs >> this->fullscreen;
				ifs >> this->frameRateLimit;
				ifs >> this->verticalSync;
				ifs >> this->contextSettings.antialiasingLevel;
			}
			ifs.close();
		}
	};
	//variables
	GraphicsSettings gfxSettings;
	sf::RenderWindow *window;
	sf::Event sfEvent;
	
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;

	//Initialization
	void initVariables();
	void initGraphicsSettings();
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