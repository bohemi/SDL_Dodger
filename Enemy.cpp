#include "Enemy.h"

Enemy::Enemy() {}
Enemy::~Enemy() {}
//function where making of enemy is happening with given numbers of rects
void Enemy::enemy_rects(int size, SDL_Rect enemy_rect[])
{
	for (int i = 0; i < size; i++)
	{
		enemy_rect[i].x = i * 70; enemy_rect[i].y = 0;
		enemy_rect[i].w = i % 40; enemy_rect[i].h = i*i % 30;
	}
}

void Enemy::enemy_render(SDL_Renderer* enemy_renderer,int size, SDL_Rect enemy_rect[])
{
	SDL_SetRenderDrawColor(enemy_renderer, 255, 0, 0, 255);
	SDL_RenderDrawRects(enemy_renderer, enemy_rect, size);//function for drawing multiple rects
	//SDL_FillRect..should be one maybe...get more info on this
}