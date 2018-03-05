#include "..\SDL\include\SDL.h"

#pragma comment (lib, "SDL2.lib")
#pragma comment (lib, "SDL2main.lib")

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 760
#define SPEED 1
#define CHAR_SIZE 75
#define BULLET_SPEED 5


int main(int argc, char* argv[]) {


	SDL_Init(SDL_INIT_EVERYTHING);


	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr; 
	SDL_Event e;
	bool exit = false;

	SDL_Rect rect;
	rect.x =  SCREEN_WIDTH/2;
	rect.y = SCREEN_HEIGHT / 2;
	rect.h = rect.w = CHAR_SIZE; 
	
	SDL_Rect bullet;
	bullet.h = 5;
	bullet.w = 20;
	bullet.x = 5000;
	bullet.y = 5000;

	bool up = false;	
	bool down = false;	
	bool left = false;
	bool right = false;
	bool shot = false; 
	bool shot_r = true;
	bool shot_l = false;




	window = SDL_CreateWindow("My Mega Super Awesome Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0
	);

	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

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
						if (shot_r == true) {
							shot_r = false;
							bullet.x = 2000;
						}
						shot_l = true; 
						break;
					case SDL_SCANCODE_RIGHT:
						right = true;
						if (shot_l == true) {
							shot_l = false;
							bullet.x = 2000;
						}
						shot_r = true; 
						break;
					case SDL_SCANCODE_ESCAPE:
						exit = true;
						break;
					case SDL_SCANCODE_SPACE:
						if (shot_r) bullet.x = rect.x + CHAR_SIZE;
						if (shot_l) bullet.x = rect.x;
						bullet.y = rect.y + (CHAR_SIZE / 2);
						break; 
					}
				}
				else if (e.type == SDL_QUIT) exit = true;
		}
		if (shot_r) bullet.x += BULLET_SPEED;
		if (bullet.x > SCREEN_WIDTH)bullet.x = 2000;
		if (shot_l) bullet.x -= BULLET_SPEED;
		if (bullet.x < 0)bullet.x = 2000;
		if (up && rect.y > 0) rect.y -= SPEED;
		if (down && rect.y < (SCREEN_HEIGHT-CHAR_SIZE))rect.y += SPEED;
		if (left && rect.x > 0)rect.x -= SPEED;
		if (right&& rect.x < (SCREEN_WIDTH-CHAR_SIZE))rect.x += SPEED;

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &bullet);


		SDL_RenderPresent(renderer);

		SDL_Delay(2);
	}

	
	return 0; 
}