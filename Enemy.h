#pragma once
#include "Game.h"

class Enemy
{
public:

	Enemy();
	~Enemy();
	//making arr of rects for multiple rect draw
	void enemy_render(SDL_Renderer* enemy_renderer, int size, SDL_Rect enemy_rect[]);
	void enemy_rects(int size, SDL_Rect enemy_rect[]);

private:
	//making random generator for Xpos,Ypos and width and height also
	int lower_val_x = 0, upper_val_x = 800;
};