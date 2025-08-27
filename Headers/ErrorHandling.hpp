#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <curl/curl.h>

void warningPrint(const char* warning){
    std::cout << "WARNING!: " << warning << std::endl;
}
