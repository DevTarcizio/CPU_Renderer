#include <SDL3/SDL.h>
#include "Renderer.hpp"


int main() {
	Renderer CPU_render;


	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("failed");
		return -1;
	};

	SDL_Window* window;
	window = SDL_CreateWindow("CPU Renderer", 800, 600, SDL_WINDOW_RESIZABLE);
	
	SDL_Renderer* render;
	render = SDL_CreateRenderer(window, 0);

	SDL_Texture* texture;
	texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, 800, 600);


	bool isRunning{ true };

	vec2i v0{ 400, 200 };
	vec2i v1{ 150, 500 };
	vec2i v2{ 650, 500 };

	CPU_render.drawFilledTriangle(v0, v1, v2);

	SDL_Event event;
	while (isRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}

		}

		


		SDL_UpdateTexture(texture, nullptr, CPU_render.getFrameBufferData(), 800 * sizeof(uint32_t));

		SDL_RenderClear(render);
		SDL_RenderTexture(render, texture, nullptr, nullptr);
		SDL_RenderPresent(render);

		SDL_Delay(16);
	}



	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();

}





