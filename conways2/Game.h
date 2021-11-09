#pragma once

#include "Menu.h"

#define WINDOW_WIDTH 1500 //1920 || 1500
#define WINDOW_HEIGHT 1000 //1080 || 1000

class Game
{
private:

	//Varibale Window
	sf::RenderWindow* Window;
	sf::VideoMode Videomode;
	sf::Event ev;

	//Menu
	Menu menu;

	//Mouse position in Window
	sf::Vector2i MousePosition;

	//Game varible
	int CELL_SIZE;
	int Game_w;
	int Game_h;

	//Game objects

	sf::RectangleShape rectangle;
	
	bool Generation[WINDOW_WIDTH / 5][WINDOW_HEIGHT / 5];
	bool OldGeneration[WINDOW_WIDTH / 5][WINDOW_HEIGHT / 5];

	//Privet functions
	void initVariables();
	void initWindow();
	void initGameValrible();
	void initRectangle();

public:

	// Constructers / Destructors
	Game();
	virtual ~Game();

	//Accesseor
	bool const running() const;

	//  Mouse Functions
	void updateMousePositions();
	void mouseGenerate();

	// Generation Functions
	void Generate_down();
	void Generate();
	void centreGenerate();
	void centreTS();
	void UpdateOldGeneration();

	//Cells Functions

	int GetCellsCount(int x, int y);
	int GetCell(int x, int y);
	
	// Menu 
	void startMenu();
	void renderMenu();

	// Rules
	int rulesNamber = 0;
	void choiceRules();
	void checkRules_1();
	void checkRules_2();
	void checkRules_3();
	void checkRules_4();

	// Step Game Function
	void update();
	void pollEvents();
	void render();

};


