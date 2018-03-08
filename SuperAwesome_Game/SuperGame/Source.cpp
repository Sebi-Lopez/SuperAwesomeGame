#include "..\SDL\include\SDL.h"
#include "..\SDL_Image\include\SDL_image.h"
#include "..\SDL_Mixer\include\SDL_mixer.h"
#include <iostream>

#pragma comment (lib, "SDL2.lib")
#pragma comment (lib, "SDL2main.lib")
#pragma comment (lib, "SDL2_Image.lib")
#pragma comment (lib, "SDL2_mixer.lib")

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 760
#define SPEED 7
#define PLAYER_SIZE 75
#define BULLET_SPEED 20
#define AMMO 20
#define BULLET_SIZE 10


struct projectile {
	
	int x, y;
	bool alive = false; 

};

//struct globals {
//
//	SDL_Window* window = nullptr;
//
//	SDL_Renderer* renderer = nullptr;
//
//	SDL_Surface* surface = nullptr;
//	SDL_Texture* background = nullptr;
//	SDL_Texture* character = nullptr;
//	SDL_Texture* fireball = nullptr;
//
//	Mix_Chunk* fx_shot = nullptr;
//	Mix_Music* music = nullptr; 
//	SDL_Rect player{ 300, SCREEN_HEIGHT / 2,PLAYER_SIZE,PLAYER_SIZE };
//	projectile shots[AMMO];
//	int last_shot = 0; 
//
//	bool up, down, right, left, fire = false; 
//}g;
//
//
//void Start() {
//
//	SDL_Init(SDL_INIT_EVERYTHING);
//	IMG_Init(IMG_INIT_PNG);
//	Mix_Init(MIX_INIT_OGG);
//
//	g.window = SDL_CreateWindow("My Super Awesome Game",
//		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//		SCREEN_WIDTH, SCREEN_HEIGHT,
//		SDL_WINDOW_SHOWN);
//
//	g.renderer = SDL_CreateRenderer(g.window, -1, SDL_RENDERER_PRESENTVSYNC);
//
//
//	//IMAGE SETTINGS
//
//	
//	g.surface = IMG_Load("assets/background.png");
//	g.background = SDL_CreateTextureFromSurface(g.renderer, g.surface);
//	SDL_FreeSurface(g.surface); 
//	
//	g.surface = IMG_Load("assets/mario.png");
//	g.character = SDL_CreateTextureFromSurface(g.renderer, g.surface);
//	SDL_FreeSurface(g.surface);
//
//	g.surface = IMG_Load("assets/fireball.png");
//	g.fireball = SDL_CreateTextureFromSurface(g.renderer, g.surface);
//	SDL_FreeSurface(g.surface);
//
//
//	//SOUND SETTINGS
//
//	Mix_OpenAudio(25000, MIX_DEFAULT_FORMAT, 2, 2500);
//	
//	g.fx_shot = Mix_LoadWAV("assets/laser.WAV"); 
//	g.music = Mix_LoadMUS("assets/background_music.ogg");
//	Mix_PlayMusic(g.music, -1);
//}
//
//
//void Finish() {
//
//	//IMAGE QUIT
//
//	SDL_DestroyTexture(g.background);
//	SDL_DestroyTexture(g.character);
//	SDL_DestroyTexture(g.fireball);
//	IMG_Quit();
//
//	//SOUND QUIT
//
//	Mix_FreeChunk(g.fx_shot);
//	Mix_FreeMusic(g.music);
//	Mix_CloseAudio();
//	Mix_Quit();
//
//	// SDL QUIT
//
//	SDL_DestroyRenderer(g.renderer); 
//	SDL_DestroyWindow(g.window);
//	SDL_Quit();
//}
//
//
//bool Check_Input() {
//	bool exit = false; 
//	SDL_Event e; 
//
//	while (SDL_PollEvent(&e) != 0) 
//	{
//		if (e.type == SDL_KEYUP)
//		{
//			switch (e.key.keysym.sym)
//			{
//			case SDLK_UP:
//				g.up = false;
//				break;
//			case SDLK_DOWN:
//				g.down = false;
//				break;
//			case SDLK_RIGHT:
//				g.right = false;
//				break;
//			case SDLK_LEFT:
//				g.left = false;
//				break;
//			}
//		}
//		if (e.type == SDL_KEYDOWN)
//		{
//			switch (e.key.keysym.scancode)
//			{
//			case SDL_SCANCODE_UP:
//				g.up = true;
//				break;
//			case SDL_SCANCODE_DOWN:
//				g.down = true;
//			case SDL_SCANCODE_RIGHT:
//				g.right = true; 
//			case SDL_SCANCODE_LEFT:
//				g.left = true; 
//			case SDL_SCANCODE_SPACE:
//				g.fire = true; 
//			case SDL_SCANCODE_ESCAPE:
//				exit = true;
//				break;
//			}
//		}			
//		if (e.type == SDL_QUIT)exit = true; 
//	}
//	return exit; 
//}
//
//void Movement() {
//
//	if (g.up)g.player.y -= SPEED;
//	if (g.down)g.player.y += SPEED;
//	if (g.left)g.player.x -= SPEED;
//	if (g.right)g.right.x += SPEED;
//
//
//	if (g.fire)
//	{
//		g.fire = false; 
//		Mix_PlayChannel(-1, g.fx_shot, 0);
//		g.shots[g.last_shot].alive = true;
//		g.shots[g.last_shot].x = g.player.x + PLAYER_SIZE;
//		g.shots[g.last_shot].y = g.player.y + (PLAYER_SIZE / 2);
//		g.last_shot++;
//	}
//
//	for (int i = 0; i < AMMO; i++)
//	{
//		if (g.shots[i].alive) {
//			g.shots[i].x += BULLET_SPEED;
//			if (g.shots[i].x > SCREEN_WIDTH)
//				g.shots[i].alive = false;
//		}
//	}
//}
//
//void Render() {	
//	SDL_Rect target; 
//
//	SDL_RenderCopy(g.renderer, g.background, NULL, NULL);			//Background
//
//	for (int i = 0; i < AMMO; i++)									//Bullets
//	{
//		target.x = g.shots[i].x;
//		target.y = g.shots[i].y;
//		SDL_RenderCopy(g.renderer, g.fireball, NULL, &target);
//	}
//
//	SDL_RenderCopy(g.renderer, g.character, NULL, g.player);		//Character
//	
//	SDL_RenderPresent(g.renderer);									//Present
//}

int main(int argc, char* argv[]) {

	bool exit = false;

	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_Init(MIX_INIT_OGG);
	IMG_Init(IMG_INIT_PNG);

	Mix_OpenAudio(25000, MIX_DEFAULT_FORMAT, 2, 2500);

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr; 
	SDL_Event e;
	SDL_Surface* surface; 
	SDL_Texture* character; 
	SDL_Texture* background; 
	SDL_Texture* fireball;
	projectile shots[AMMO];
	int last_shot = 0;
	SDL_Rect rect;
	

	rect.x =  SCREEN_WIDTH/2;
	rect.y = SCREEN_HEIGHT / 2;
	rect.h = rect.w = PLAYER_SIZE; 
	int bullet_num = 0;
	

	bool up = false;	
	bool down = false;	
	bool left = false;
	bool right = false;
	bool shot = false; 
	bool fire = false; 

	window = SDL_CreateWindow("My Mega Super Awesome Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0
	);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);


	surface = IMG_Load("assets/mario.png");
		if (!surface) exit = true;
	character = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("assets/background.png");
		if (!surface) exit = true;

	background = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("assets/fireball.png");
		if (!surface) exit = true;
	fireball = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface); 



	Mix_Chunk* sample;

	sample = Mix_LoadWAV("assets/loser.WAV");
	if (!sample)exit = true;

	Mix_Music* music; 

	music = Mix_LoadMUS("assets/background_music.ogg");
	if (!music)exit = true;

	Mix_PlayMusic(music, -1);


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
						fire = true; 
						

						break; 
					}
				}
				else if (e.type == SDL_QUIT) exit = true;
		}
		
		if (fire) {
			Mix_PlayChannel(-1, sample, 0);
			if (last_shot == AMMO) last_shot = 0; 
			shots[last_shot].alive = true; 
			shots[last_shot].x = rect.x + (PLAYER_SIZE);
			shots[last_shot].y = rect.y + (PLAYER_SIZE / 2);
			last_shot++;
			fire = false; 
		}

		for (int i = 0; i < AMMO; i++) {
			if (shots[i].alive)
			{
				shots[i].x += BULLET_SPEED;
				if (shots[i].x > SCREEN_WIDTH) shots[i].alive = false; 
			}
		}

		if (up && rect.y > 0) rect.y -= SPEED;
		if (down && rect.y < (SCREEN_HEIGHT-195))rect.y += SPEED;
		if (left && rect.x > -20)rect.x -= SPEED;
		if (right&& rect.x < (SCREEN_WIDTH-PLAYER_SIZE))rect.x += SPEED;

		SDL_Rect target;
		target.h = 20;
		target.w = 20;

		SDL_RenderCopy(renderer, background, NULL, NULL);
		
		for(int i=0;i<AMMO;i++){
			if (shots[i].alive == true) 
			{
				target.x = shots[i].x;
				target.y = shots[i].y;
				SDL_RenderCopy(renderer, fireball, NULL, &target); 
			}
		}	
		SDL_RenderCopy(renderer, character, NULL, &rect);
	
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	IMG_Quit();

	Mix_FreeChunk(sample);
	Mix_FreeMusic(music); 
	Mix_CloseAudio();
	Mix_Quit();
	

	return 0; 
}