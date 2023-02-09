#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "iostream"
#include "sstream"

class Game
{
public:
	Game();
	~Game();

	void create_window(const char* title, int window_pos_x, int window_pos_y, int window_width, int window_height, int flag);
	void render();
	void rect();
	void input();
	void ttf();
	void update();
	void detect_collision();
	bool running() { return is_running; }
	void clean();

private:

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event event;
	SDL_Rect player_rect, TTF_rec;
	TTF_Font* font_open = nullptr;
	const char* file_name = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;

	int window_width = 800, window_height = 600;
	int player_direction_up = 300, player_direction_right = 400;
	int player_rect_w = 12, player_rect_h = 15;
	double player_speed = 2.4;
	bool is_running;

	//player directions tracker
	bool b_player_up = false;
	bool b_player_down = false;
	bool b_player_left = false;
	bool b_player_right = false;

	//for enemy class
	const static int size_enemy = 10000;
	SDL_Rect enemy_rect[size_enemy];
	int fall_speed = 0.5;
	int spawn_boundary_x, spawn_boundary_y;
	int collision_count;
	int TTF_score;
};