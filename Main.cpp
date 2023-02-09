#include "Game.h"

//and do not give updation of key movement inside event function make bool for key true or false
//because events are uncertain and wont give updation accurately

					//keep track of memory leak

// only search x and find x and focus on x at a time

Game* game_class = nullptr;

int main(int argc, char* argv[])
{
	const short FPS = 60;
	const short frame_delay = 1000 / FPS;
	Uint32 frame_start;
	int frame_end;

	game_class = new Game();
	//initialization of everything that is non loopable
	game_class->create_window("Dodger", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

	while (game_class->running())
	{
		frame_start = SDL_GetTicks();
		//call class function
		game_class->input();
		game_class->rect();
		game_class->update();
		game_class->detect_collision();
		game_class->render();

		frame_end = SDL_GetTicks() - frame_start;

		if (frame_delay > frame_end)
		{
			SDL_Delay(frame_delay - frame_end);
		}
	}
	game_class->clean();

	return 0;
}