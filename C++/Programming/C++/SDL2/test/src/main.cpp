/* ========================================================================
 *
 *     Filename:  
 *  Description:  
 *       Author:  
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <iostream>
#include <SDL2/SDL.h>
#include <memory>

template<typename T>
using ptr = T*;

template<typename T>
using ref = T&;

auto main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) -> int
{
	auto window = std::shared_ptr<SDL_Window>(SDL_CreateWindow("Window title here.", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN), SDL_DestroyWindow);

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cerr << "ERR: Video initialization error: " << SDL_GetError() << "\n";
	else {
		if (window == nullptr)
			std::cerr << "ERR: Window creation error: " << SDL_GetError() << "\n";
		else {
			auto window_surface = std::unique_ptr<SDL_Surface>(SDL_GetWindowSurface(window.get()));
			auto image_surface = std::unique_ptr<SDL_Surface>(SDL_LoadBMP("image.bmp"));
			if (image_surface == nullptr)
				std::cerr << "ERR: Loading bitmap image: " << SDL_GetError() << "\n";
			else {
				SDL_BlitSurface(image_surface.get(), nullptr, window_surface.get(), nullptr);

				SDL_UpdateWindowSurface(window.get());
				SDL_Delay(2000);
				auto a = 0;
				std::cin >> a;
			}
		}

	}

	SDL_Quit();
	return 0;
}

