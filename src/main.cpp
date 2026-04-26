#include <SDL3/SDL.h>
#include "../core/Renderer.hpp"


int main() {
	const int width{ 1920 };
	const int height{ 991 };
	
	Renderer CPU_render;
	uint32_t currentColor{ CPU_render.toRGBA(Renderer::Color::Green) };

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("failed");
		return -1;
	};

	SDL_Window* window;
	window = SDL_CreateWindow("CPU Renderer", width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
	
	SDL_Renderer* render;
	render = SDL_CreateRenderer(window, 0);

	SDL_Texture* texture;
	// Usando pixelformat ABGR pois assim ele usa como RGBA
	texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_ABGR32, SDL_TEXTUREACCESS_STREAMING, width, height);


	bool isRunning{ true };

	vec2i v0{ 400, 200 };
	vec2i v1{ 150, 500 };
	vec2i v2{ 650, 500 };

	SDL_Event event;
	while (isRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}

		}

		CPU_render.drawFilledTriangle(v0, v1, v2, currentColor);
		
		SDL_UpdateTexture(texture, nullptr, CPU_render.getFrameBufferData(), width * sizeof(uint32_t));

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





