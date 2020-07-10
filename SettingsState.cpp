#include "stdafx.h"
#include "SettingsState.h"

SettingsState::SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states )
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
	this->initText();
}

SettingsState::~SettingsState()
{

	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}

	for (auto it = this->dropDownLinsts.begin(); it != this->dropDownLinsts.end(); ++it) {
		delete it->second;
	}
	
}

//Initializer functions
void SettingsState::initVariables()
{
	this->videoModes = sf::VideoMode::getFullscreenModes();
}

void SettingsState::initBackground()
{
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png "))
	{
		throw"ERROR::MAIN_MENUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);


}

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void SettingsState::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");
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

void SettingsState::initGui()
{

	this->buttons["BACK"] = new gui::Button(1500.f, 880.f, 250.f, 50.f,
		&this->font, "Back", 50,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["APPLY"] = new gui::Button(1300.f, 880.f, 250.f, 50.f,
		&this->font, "Apply", 50,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	std::vector<std::string> videoModes_str;

	for (auto& i : this->videoModes) 
	{
		videoModes_str.push_back(std::to_string(i.width) + 'x' + std::to_string(i.height));
	}
	
	this->dropDownLinsts["RESOLUTION"] = new gui::DropDownList(800, 450, 200, 50, font, videoModes_str.data(), videoModes_str.size());
}

void SettingsState::initText()
{
	this->optionsText.setFont(this->font);

	this->optionsText.setPosition(sf::Vector2f(100.f, 450.f));

	this->optionsText.setCharacterSize(30);
	this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));

	this->optionsText.setString(
		"Resolution \n\nFullscreen \n\nVsync \n\nAntialiasing \n\n"
	);
}

//Functions
void SettingsState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {

	}


}

void SettingsState::updateGui(const float& dt)
{
	/*Updates all the gui elements in the state and handles their functionality.*/
	
	//Buttons functionality
	for (auto& it : this->buttons) {
		it.second->update(this->mousePosView);
	}

	//Quit the Game
	if (this->buttons["APPLY"]->isPressed()) {

		//TEST REMOVE LATER
		this->window->create(this->videoModes[this->dropDownLinsts["RESOLUTION"]->getActiveElementId()], "test", sf::Style::Default);
	}


	//Applay selected setting
	if (this->buttons["BACK"]->isPressed()) {
		this->endState();
	}


	//Dropdownlist
	for (auto i : this->dropDownLinsts)
	{
		i.second->update(this->mousePosView, dt);
	}
	//Dropdownlists functionality
	
}


void SettingsState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateGui(dt);

	

	//system("cls");
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
}

void SettingsState::renderGui(sf::RenderTarget& target)
{
	for (auto& it : this->buttons) {
		it.second->render(target);
	}

	for (auto i : this->dropDownLinsts)
	{
		i.second->render(target);
	}
}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderGui(*target);

	target->draw(this->optionsText);

	

	//REMOVE LATER!!!
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);

}
