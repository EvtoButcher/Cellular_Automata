#include "Menu.h"

//Privet functions//////////////////////////////////

void Menu::initTexture()
{
	menuTexture1.loadFromFile("Pictures\\auto.png");
	menuTexture2.loadFromFile("Pictures\\draw.png");
	menuTexture3.loadFromFile("Pictures\\exit.png");
	modeTexture1.loadFromFile("Pictures\\B3_S23.png");
	modeTexture2.loadFromFile("Pictures\\B3_S(ALL).png");
	modeTexture3.loadFromFile("Pictures\\90.png");
	modeTexture4.loadFromFile("Pictures\\30.png");

	Auto.setTexture(menuTexture1); 
	Draw.setTexture(menuTexture2); 
	Exit.setTexture(menuTexture3); 
	B3.setTexture(modeTexture1);
	B1.setTexture(modeTexture2);
	T90.setTexture(modeTexture3);
	T30.setTexture(modeTexture4);

	Auto.setPosition(50, -100);
	Draw.setPosition(50, 20);
	Exit.setPosition(50, 140);
	B3.setPosition(50, -110);
	B1.setPosition(200, -110);
	T90.setPosition(-100, -110);
	T30.setPosition(350, -110);

	B3.setColor(sf::Color(73, 123, 0));
	B1.setColor(sf::Color(73, 123, 0));
	T90.setColor(sf::Color(73, 123, 0));
	T30.setColor(sf::Color(73, 123, 0));
}

// Constructers / Destructors///////////////////////

Menu::Menu()
{
	this->initTexture();
}

Menu::~Menu()
{
}

//Accesseor////////////////////////////////////////

bool Menu::EventIS(sf::RenderWindow* Window)
{
	return Window->pollEvent(menu_event);
}

// Step Game Function/////////////////////////////// 

int Menu::updateMenu_2()
{
	return menuNum;
}

int Menu::updateMenu(sf::RenderWindow* Window)
{
	while (Window->pollEvent(menu_event)) {

		if (menu_event.type == sf::Event::Closed) { Window->close(); }

		//B3
		if (sf::IntRect(126 * 5, 36 * 5, 110, 100).contains(sf::Mouse::getPosition(*Window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			B3.setColor(sf::Color(129, 181, 54));

			B1.setColor(sf::Color(73, 123, 0));

			T90.setColor(sf::Color(73, 123, 0));

			T30.setColor(sf::Color(73, 123, 0));

			aL.setColor(sf::Color(73, 123, 0));

			Rules = 1;

		}
		//B1
		if (sf::IntRect(155 * 5, 36 * 5, 110, 100).contains(sf::Mouse::getPosition(*Window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			B1.setColor(sf::Color(129, 181, 54));

			B3.setColor(sf::Color(73, 123, 0));

			T90.setColor(sf::Color(73, 123, 0));

			T30.setColor(sf::Color(73, 123, 0));

			aL.setColor(sf::Color(73, 123, 0));

			Rules = 2;
		}

		//90
		if (sf::IntRect(100 * 5, 36 * 5, 110, 100).contains(sf::Mouse::getPosition(*Window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			T90.setColor(sf::Color(129, 181, 54));

			B3.setColor(sf::Color(73, 123, 0));

			B1.setColor(sf::Color(73, 123, 0));

			T30.setColor(sf::Color(73, 123, 0));

			aL.setColor(sf::Color(73, 123, 0));

			Rules = 3;
		}

		//30
		if (sf::IntRect(186 * 5, 36 * 5, 110, 100).contains(sf::Mouse::getPosition(*Window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			T30.setColor(sf::Color(129, 181, 54));

			B3.setColor(sf::Color(73, 123, 0));

			B1.setColor(sf::Color(73, 123, 0));

			T90.setColor(sf::Color(73, 123, 0));

			aL.setColor(sf::Color(73, 123, 0));

			Rules = 4;
		}

		//Auto
		if (sf::IntRect(126 * 5, 61 * 5, 270, 100).contains(sf::Mouse::getPosition(*Window))) {

			Auto.setColor(sf::Color(129, 181, 54));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { 
				
				menuNum = 1; 
				updateMenu_2();
			}
		}
		else { Auto.setColor(sf::Color(73, 123, 0)); }

		//Draw
		if (sf::IntRect(126 * 5, 85 * 5, 270, 100).contains(sf::Mouse::getPosition(*Window))) {

			Draw.setColor(sf::Color(129, 181, 54));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				menuNum = 2;
				updateMenu_2();
			}
		}
		else { Draw.setColor(sf::Color(73, 123, 0)); }

		//Exit
		if (sf::IntRect(126 * 5, 109 * 5, 270, 100).contains(sf::Mouse::getPosition(*Window))) {

			Exit.setColor(sf::Color(129, 181, 54));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { Window->close(); }
		}
		else { Exit.setColor(sf::Color(73, 123, 0)); }
	}

	std::cout << Rules << std::endl;

	return Rules;
}

void Menu::renderMenu(sf::RenderTarget* Target)
{
	Target->draw(this->B3);
	Target->draw(this->B1);
	Target->draw(this->T90);
	Target->draw(this->T30);
	Target->draw(this->Auto);
	Target->draw(this->Draw);
	Target->draw(this->Exit);
}

