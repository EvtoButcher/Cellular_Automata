#include "Game.h"

//Privet functions//////////////////////////////////

void Game::initVariables()
{
	this->Window = nullptr;
}

void Game::initWindow()
{
	this->Videomode.height = WINDOW_HEIGHT;
	this->Videomode.width = WINDOW_WIDTH;

	
	this->Window = new sf::RenderWindow(this->Videomode, "Game of Life", sf::Style::Close);
	this->Window->setFramerateLimit(22);
}

void Game::initGameValrible()
{
	this->CELL_SIZE = 5;
	this->Game_h = Videomode.height / CELL_SIZE;
	this->Game_w = Videomode.width / CELL_SIZE;
}

void Game::initRectangle()
{
	this->rectangle.setFillColor(sf::Color(88, 123, 37));
	this->rectangle.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
}

// Constructers / Destructors///////////////////////

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initGameValrible();
	this->initRectangle();
}

Game::~Game()
{
	delete this->Window;
}

//Accesseor////////////////////////////////////////

bool const Game::running() const
{
	return this->Window->isOpen();
}

// Mouse Functions/////////////////////////////////

void Game::updateMousePositions()
{
	this->MousePosition = sf::Mouse::getPosition(*this->Window) / CELL_SIZE;

}

void Game::mouseGenerate()
{
	//if ((menu.updateMenu(Window) == 2 && menu.updateMenu_2() == 2) || (menu.updateMenu(Window) == 3 && menu.updateMenu_2() == 2)) {
	//	Generation[MousePosition.x][MousePosition.y] = OldGeneration[MousePosition.x][MousePosition.y] = true;
	//}

	if (rulesNamber == 2 || rulesNamber == 3) {
	
		if (menu.updateMenu_2() != 1) {
			Generation[MousePosition.x][MousePosition.y] = OldGeneration[MousePosition.x][MousePosition.y] = true;
		}
	}

	if (rulesNamber == 1) {
		Generation[MousePosition.x][MousePosition.y] = OldGeneration[MousePosition.x][MousePosition.y] = true;
		Generation[MousePosition.x + 1][MousePosition.y] = OldGeneration[MousePosition.x + 1][MousePosition.y] = true;
		Generation[MousePosition.x + 1][MousePosition.y - 1] = OldGeneration[MousePosition.x + 1][MousePosition.y - 1] = true;
		Generation[MousePosition.x][MousePosition.y - 1] = OldGeneration[MousePosition.x][MousePosition.y - 1] = true;
	}

}

// Generation Functions////////////////////////////

void Game::Generate_down()
{
	
	for (int y = 0; y < Game_h; y++) {
		for (int x = 0; x < Game_w; x++) {

			Generation[x][y] = OldGeneration[x][y] = false;

		}
	}
}

void Game::Generate()
{
	for (int y = 0; y < Game_h; y++) {
		for (int x = 0; x < Game_w; x++) {

			if (rand() % 2 == 1) {

				Generation[x][y] = OldGeneration[x][y] = true;
			}
			else {

				Generation[x][y] = OldGeneration[x][y] = false;
			}
		}
	}
}

void Game::centreGenerate()
{
	if(menu.updateMenu_2() == 1){ Generation[Game_w / 2][Game_h / 2] = OldGeneration[Game_w / 2][Game_h / 2] = true; }
}

void Game::centreTS()
{
	if (menu.updateMenu_2() == 1) { Generation[Game_w / 2][Game_h + 1] = OldGeneration[Game_w / 2][Game_h + 1] = true; }
}

void Game::UpdateOldGeneration()
{
	for (int y = 0; y < Game_h; y++) {
		for (int x = 0; x < Game_w; x++) {

			OldGeneration[x][y] = Generation[x][y];
		}
	}
}

//Cells Functions//////////////////////////////////

int Game::GetCellsCount(int x, int y)
{
	return GetCell(x - 1, y) + GetCell(x - 1, y - 1) + GetCell(x, y - 1) + GetCell(x + 1, y - 1) +
		GetCell(x + 1, y) + GetCell(x + 1, y + 1) + GetCell(x, y + 1) + GetCell(x - 1, y + 1);
}

int Game::GetCell(int x, int y)
{
	if ((x < 0) || (x > Game_w - 1) || (y < 0) || (y > Game_h - 1)) {

		return 0;
	}
	else {

		return OldGeneration[x][y];
	}
}

// Menu Funcrion///////////////////////////////////

void Game::startMenu()
{
	
	while (running()) {

		//std::cout << "Menu: " << menu.updateMenu(this->Window) << " Menu_2: " <<menu.updateMenu_2() << std::endl;		
		
		choiceRules();

		//Chose Menu		
		if (menu.updateMenu(this->Window) == 1) {

			if (menu.updateMenu_2() == 1) { Generate(); break; }

			if (menu.updateMenu_2() == 2) { break; }
		}

		if (menu.updateMenu(this->Window) == 2) {

			if (menu.updateMenu_2() == 1) { centreGenerate(); break; }

			if (menu.updateMenu_2() == 2) { break; }
		}

		if (menu.updateMenu(this->Window) == 3) {

			if (menu.updateMenu_2() == 1) { centreTS(); break; }

			if (menu.updateMenu_2() == 2) { break; }
		}

		
		std::cout << "startMenu() is start" << std::endl;
		//Render Menu
		
		renderMenu();
	}
}

// Rules///////////////////////////////////////////

void Game::choiceRules()
{
	std::cout << "choiceRules is start" << std::endl;
	
	//B3
	if (menu.updateMenu(this->Window) == 1) { rulesNamber = 1; }
	//B1
	if (menu.updateMenu(this->Window) == 2) { rulesNamber = 2; }
	//TS
	if (menu.updateMenu(this->Window) == 3) { rulesNamber = 3; }

}

void Game::checkRules_1()
{
	
	for (int y = 0; y < Game_h; y++) {
		for (int x = 0; x < Game_w; x++) {

			int cellsCount = this->GetCellsCount(x, y);

			if (OldGeneration[x][y] == false) {

				if (cellsCount == 3) {

					Generation[x][y] = true;

				}
			}
			else {

				if ((cellsCount < 2) || (cellsCount > 3)) {

					Generation[x][y] = false;

				}
			}
		}
	}
	
}

void Game::checkRules_2()
{
	for (int y = 1; y < Game_h - 1; y++) {
		for (int x = 1; x < Game_w - 1; x++) {

			int cellsCount = GetCellsCount(x, y);

			if (OldGeneration[x][y] == false) {

				if (cellsCount == 1) {

					Generation[x][y] = true;

				}
			}
		}
	}
}

void Game::checkRules_3()
{
	for (int y = 1; y < Game_h - 1; y++) {
		for (int x = 1; x < Game_w - 1; x++) {

			int cellsCount = GetCellsCount(x, y);

			Generation[x][y+1] = OldGeneration[x - 1][y] ^ OldGeneration[x + 1][y];
		}
	}
}

// Step Game Function///////////////////////////////

void Game::update()
{
	this->pollEvents();

	this->UpdateOldGeneration();

	if (rulesNamber == 1) { this->checkRules_1(); }

	if (rulesNamber == 2) { this->checkRules_2(); }

	if (rulesNamber == 3) { this->checkRules_3(); }

}

void Game::pollEvents()
{
	while (this->Window->pollEvent(ev)) {

		if (ev.type == sf::Event::Closed) { Window->close(); }

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { Window->close(); }

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) { rulesNamber = 1; }//////////////////////////////

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			this->updateMousePositions();

			this->mouseGenerate();
		}
	}
}

//Render Function /////////////////////////////////

void Game::render()
{
	this->Window->clear();

	//Draw objects

	for (int y = 0; y < Game_h; y++) {

		for (int x = 0; x < Game_w; x++) {

			if (Generation[x][y]) {

				this->rectangle.setPosition(x * CELL_SIZE, y * CELL_SIZE);

				this->Window->draw(rectangle);
			}
		}
	}

	this->Window->display();
}

void Game::renderMenu()
{
	this->Window->clear();

	this->menu.renderMenu(this->Window);

	this->Window->display();
}
