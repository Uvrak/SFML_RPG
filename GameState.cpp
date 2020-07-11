#include "stdafx.h"
#include "GameState.h"

// initializer Functions
void GameState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");
	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void GameState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void GameState::initTextures()
{
	//f(!this->textures["PLAYER_IDLE"].loadFromFile("Resources/Images/Sprites/Avatar/tiles0721_16.png"))
	if(!this->textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Sprites/Player/PLAYER_SHEET.png"))
		throw("ERROR::GEMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE");
}

void GameState::initPauseMenu()
{
	this->pMenu = new PauseMenu(*this->window, this->font);
	this->pMenu->addButton("QUIT", 800.f, "Quit");
}

void GameState::initPlayers()
{
	this->player = new Player(0, 0, this->textures["PLAYER_SHEET"]);
}

void GameState::initTileMap()
{
	this->tileMap = new TileMap(this->stateData->gridSize, 10, 10);
}

//Constructors /Destructors
GameState::GameState(StateData* state_data)
	: State(state_data)
{
	this->initKeybinds();
	this->initFonts();
	this->initTextures();
	this->initPauseMenu();
	this->initPlayers();
	this->initTileMap();
	
}

GameState::~GameState()
{
	delete this->pMenu;
	delete this->player;
	delete this->tileMap;
}

void GameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime())
	{
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
	}
}

void GameState::updatePlayerInput(const float& dt)
{
	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(0.f, 1.f, dt);		
}

void GameState::updatePauseMenuButtons()
{
	if (this->pMenu->isButtonPressed("QUIT"))
		this->quit = true;
}


void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updatekeytime(dt);
	this->updateInput(dt);

	if (!this->paused) //Unpuased update
	{
		this->updatePlayerInput(dt);

		this->player->update(dt);
	}

	else //paused update
	{		
		this->pMenu->update(this->mousePosView);
		this->updatePauseMenuButtons();
	}
	
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) 
		target = this->window;
	
	//this->map.render(*target);

	this->player->render(*target);

	if (this->paused) // Pause menu render
	{
		this->pMenu->render(*target);
	}
	
	
}
