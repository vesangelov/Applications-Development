#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

#include <SDL2/SDL.h>

SDL_Window* gWindow = nullptr;
SDL_Surface* globalScreenSurface = nullptr; 
SDL_Surface* globalImage = nullptr;

static void draw(){
    SDL_BlitSurface(globalImage, nullptr, globalScreenSurface, nullptr);

    if(EXIT_SUCCESS != SDL_UpdateWindowSurface(gWindow)){
        std::cerr << "SDL_UpdateWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
        return;
    }

	SDL_UpdateWindowSurface(gWindow);
	SDL_Delay(3000);
}

static int32_t loadResources(){
    const std::string filePath = "../resources/hello.bmp";
    globalImage = SDL_LoadBMP(filePath.c_str());

    if(globalImage == nullptr){
        std::cerr << "SDL_LoadBMP() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int32_t init(){

    SDL_Init(SDL_INIT_VIDEO);

    if(EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO)){
        std::cerr << "SDL_Init() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    const std::string windowName = "Hello, World!";
    const int32_t windowsX = SDL_WINDOWPOS_UNDEFINED;
    const int32_t windowsY = SDL_WINDOWPOS_UNDEFINED;
    const int32_t windowWidth = 640;
    const int32_t windowHeight = 480;

    gWindow = SDL_CreateWindow(windowName.c_str(), windowsX, 
    windowsY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

    if(gWindow == nullptr){
        std::cerr << "SDL_CreateWindow failed. Reason: " << SDL_GetError() << std::endl;
    }

    globalScreenSurface = SDL_GetWindowSurface(gWindow);

    if(globalScreenSurface == nullptr){
        std::cerr << "SDL_CreateWindow failed. Reason: " << SDL_GetError() << std::endl;
    }

    if(EXIT_SUCCESS != loadResources()){
        std::cerr << "loadResources() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int32_t deinit(){
    SDL_FreeSurface(globalImage);

    if(gWindow != nullptr){
        SDL_DestroyWindow(gWindow);
        gWindow = nullptr;
    }

    SDL_Quit();
}

int32_t main(int32_t [[__attribute_maybe_unused__]]argc, char* [[__attribute_maybe_unused__]]argv[]){

    if(EXIT_SUCCESS != init()){
        std::cerr << "init() failed" << std::endl;
        return EXIT_FAILURE;
    }

    draw();

    deinit();

    return EXIT_SUCCESS;
}



