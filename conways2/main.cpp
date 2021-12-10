
/*
	- game.Menu() -> rulesNamber ; game.Menu_2() -> rulesNamber_2
	- checkRules_3(); down;
	- ESC -> Pouse
*/

#include "Game.h"


int main()
{

	srand(time(NULL));
	
	Game game;

	//Chose Menu		
	game.startMenu();

	while (game.running()) {
		
		//Update
		game.update();

		//Render
		game.render();
	}

	return 0;
}

	