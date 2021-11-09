#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <cstdlib>
#include <sstream>
#include <Windows.h>
#include <iostream>

class Menu
{
private:
	
	sf::Event menu_event;

	// Texture Varibale
	sf::Texture menuTexture1, menuTexture2, menuTexture3, modeTexture1, modeTexture2, modeTexture3, modeTexture4;
	sf::Sprite Auto, Draw, Exit, B3, B1, T90, T30;

	// Private Funcrion  
	void initTexture();

	//Menu varibale
	int Rules = 0;
	int menuNum = 0;

public:

	// Constructers / Destructors
	Menu();
	~Menu();

	//Accesseor
	bool EventIS(sf::RenderWindow* Window);

	// Step Game Function 
	int updateMenu(sf::RenderWindow* Window);
	int updateMenu_2();
	void renderMenu(sf::RenderTarget* Target);
};


