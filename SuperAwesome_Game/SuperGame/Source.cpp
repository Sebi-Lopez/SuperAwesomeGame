#include "..\SDL\include\SDL.h"
#include "..\SDL_Image\include\SDL_image.h"
#include <iostream>

#pragma comment (lib, "SDL2.lib")
#pragma comment (lib, "SDL2main.lib")
#pragma comment (lib, "SDL2_Image.lib")

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 760
#define SPEED 1
#define CHAR_SIZE 75
#define BULLET_SPEED 5
#define AMMO 30
#define BULLET_SIZE 10
int main(int argc, char* argv[]) {


	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr; 
	SDL_Event e;
	SDL_Surface* surface; 
	SDL_Texture* character; 
	SDL_Texture* background; 
	bool exit = false;

	SDL_Rect rect;
	rect.x =  SCREEN_WIDTH/2;
	rect.y = SCREEN_HEIGHT / 2;
	rect.h = rect.w = CHAR_SIZE; 
	int bullet_num = 0;
	SDL_Rect bullet[AMMO];
	
	for (int i = 0; i < AMMO; i++) {
		bullet[i].h = BULLET_SIZE;
		bullet[i].w = BULLET_SIZE;
		bullet[i].x = 2000;
		bullet[i].y = 2000;
	}

	bool up = false;	
	bool down = false;	
	bool left = false;
	bool right = false;
	bool shot = false; 


	window = SDL_CreateWindow("My Mega Super Awesome Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0
	);

	renderer = SDL_CreateRenderer(window, -1, 0);

	surface = IMG_Load("mario.png");


	while (!exit) {
		
		while (SDL_PollEvent(&e)!=0) {

				if (e.type == SDL_KEYUP)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_UP: 
						up = false; 
						break; 
					case SDLK_DOWN: 
						down = false; 
						break;
					case SDLK_LEFT:
						left = false;
						break;
					case SDLK_RIGHT:
						right = false; 
						break;
					}
				}
				else if (e.type == SDL_KEYDOWN)
				{
					switch (e.key.keysym.scancode)
					{
					case SDL_SCANCODE_UP:
						up = true;
						break;
					case SDL_SCANCODE_DOWN:
						down = true;
						break;
					case SDL_SCANCODE_LEFT:
						left = true;
						break;
					case SDL_SCANCODE_RIGHT:
						right = true;
						break;
					case SDL_SCANCODE_ESCAPE:
						exit = true;
						break;
					case SDL_SCANCODE_SPACE:
						shot = true; 
						bullet[bullet_num].x = rect.x +(CHAR_SIZE - 20);
						bullet[bullet_num].y = rect.y + (CHAR_SIZE / 2);
						bullet_num++;
						if (bullet_num == AMMO)bullet_num = 0;
						break; 
					}
				}
				else if (e.type == SDL_QUIT) exit = true;
		}
		
		for (int i = 0; i < AMMO; i++) {
			if (shot) bullet[i].x += BULLET_SPEED;
		}

		if (up && rect.y > 0) rect.y -= SPEED;
		if (down && rect.y < (SCREEN_HEIGHT-CHAR_SIZE))rect.y += SPEED;
		if (left && rect.x > 0)rect.x -= SPEED;
		if (right&& rect.x < (SCREEN_WIDTH-CHAR_SIZE))rect.x += SPEED;

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		for (int i = 0; i < AMMO; i++) {
			SDL_RenderFillRect(renderer, &bullet[i]);
		}
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
		


		SDL_RenderPresent(renderer);

		SDL_Delay(2);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();
	return 0; 
}