#include "Enemy.h"
//player class
Game::Game() {}
Game::~Game() {}
//enemy class
Enemy* enemy_class = new Enemy();

void Game::create_window(const char* title, int window_pos_x, int window_pos_y, 
						 int window_width, int window_height, int flag)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		TTF_Init();//fonts initialized
		font_open = TTF_OpenFont(file_name = "Assets/Fonts/pixel_fonts.TTF", 30);
		
		window = SDL_CreateWindow(title, window_pos_x, window_pos_y, window_width, window_height, flag);
		if (window)
		{
			renderer = SDL_CreateRenderer(window, -1, 0);
			is_running = true;
		}
	}
	else
		is_running = false;
}

void Game::detect_collision()
{
	collision_count;
	//falling of enemy rect speed
	fall_speed ++;
	/*since rec are in linear x pos, have to make int for detecting if x of enemy_rec is greater
	than boundary of window x */
	spawn_boundary_y = 0;
	spawn_boundary_x = 0;
	//checking for player and enemy collision for multiple objects
	//a very basic loop through method for checking easch collision
	for (int i = 0; i < size_enemy; i++)
	{
		enemy_rect[i].y += fall_speed;
		/* put them above the below rec.and increment the value
		   for next rec whic is more than window x boundary */
		if (enemy_rect[i].x > 800)
		{
			enemy_rect[i].x = spawn_boundary_x;
			enemy_rect[i].y = spawn_boundary_y;
			spawn_boundary_x += 50;
			enemy_rect[i].y += fall_speed;

			if (spawn_boundary_x >= 770)
			{
				spawn_boundary_x = 0;
				spawn_boundary_y -= 70;
			}
		}
		
		if (player_rect.x > enemy_rect[i].x && player_rect.x < enemy_rect[i].x + 20
			&& player_rect.y > enemy_rect[i].y && player_rect.y < enemy_rect[i].y + 20)
		{
			collision_count+=1;
			TTF_score++;//font score increment
			ttf();
			std::cout << collision_count << "\n";
		}
	}
}

void Game::rect()
{
	//TTF rec init
	TTF_rec.x = window_width / 2;
	TTF_rec.y = window_height - 50;
	TTF_rec.w = 30;
	TTF_rec.h = 50;
	//initialize player rect. positions
	player_rect.x = player_direction_right; player_rect.y = player_direction_up; //default mid down val
	player_rect.w = player_rect_w; player_rect.h = player_rect_h;
	//init enemy rects
	enemy_class->enemy_rects(size_enemy,enemy_rect);
}

void Game::ttf()
{
	surface = TTF_RenderText_Solid(font_open, std::to_string(TTF_score).c_str()/*casting of int to str*/, { 0XFF, 0XFF, 0XFF });
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Game::update()
{
	//checks and updates enemy_class updates

	/* if bool true then give the speed value corresponding to keys
	   and stopping player from going beyond boundaries */
	if (b_player_up == true && player_direction_up > 0)
	{
		player_direction_up -= player_speed;
	}
	else if (b_player_down == true && player_direction_up < window_height - player_rect.h)
	{
		player_direction_up += player_speed;
	}
	else if (b_player_left == true && player_direction_right > 0)
	{
		player_direction_right -= player_speed;
	}
	else if (b_player_right == true && player_direction_right < window_width - player_rect.w)
	{
		player_direction_right += player_speed;
	}
}

void Game::render()
{
	/* first set color then present it and then clears it
	then again we gives color to rect and and fill and present it */
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	//enemy class renderer..giving size and numbers of rects to render
	enemy_class->enemy_render(renderer, size_enemy, enemy_rect);
	
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &player_rect);
	//SDL_RenderCopy(renderer, texturetwo, nullptr, nullptr);
	SDL_RenderCopy(renderer, texture, nullptr, &TTF_rec);//TTF renderer

	SDL_RenderPresent(renderer);
}

void Game::input()
{
	while (SDL_PollEvent(&event))
	{
		//starts player movement if key is pressed
		switch (event.type)
		{
		case SDL_QUIT:
			std::cout << "Window Band Hogyi\n";
			is_running = false;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				is_running = false;
				std::cout << "Window Band Hogyi\n";

			case SDLK_UP:
				//std::cout << "UP\n";
				b_player_up = true;
				break;

			case SDLK_DOWN:
				//std::cout << "DOWN\n";
				b_player_down = true;
				break;

			case SDLK_LEFT:
				//std::cout << "LEFT\n";
				b_player_left = true;
				break;

			case SDLK_RIGHT:
				//std::cout << "RIGHT\n";
				b_player_right = true;
				break;
			}
		}
		//stops player movement if key is released
		switch (event.type)
		{
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				//std::cout << "UP_UP\n";
				b_player_up = false;
				break;
			case SDLK_DOWN:
				//std::cout << "DOWN_UP\n";
				b_player_down = false;
				break;
			case SDLK_LEFT:
				//std::cout << "LEFT_UP\n";
				b_player_left = false;
				break;
			case SDLK_RIGHT:
				//std::cout << "RIGHT_UP\n";
				b_player_right = false;
				break;
			}
		}
	}
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_CloseFont(font_open);
	TTF_Quit();
}