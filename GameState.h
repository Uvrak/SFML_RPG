#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Player.h"
#include "PauseMenu.h"

class GameState :public State
{
private:
	Player *player;
	PauseMenu pMenu;
	//Functions
	void initKeybinds();
	void initTextures();
	void initPlayers();
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int> *supportedKeys, std::stack<State*>* states);
	virtual ~GameState();

	//Functions
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);


};

#endif