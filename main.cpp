#include "Game.h"

//ZOOOOOOOOOOOM IN BEFORE RECORDING!

int main()
{
	Game game("YOUTUBE_TUTORIAL",
		640, 480,
		4, 5,
		false);

	//MAIN LOOP
	while (!game.getWindowShouldClose())
	{
		//UPDATE INPUT ---
		game.update();
		game.render();	
	}

	return 0;
}