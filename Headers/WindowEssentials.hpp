#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <curl/curl.h>

struct window
{
    SDL_Window* windowobj;
    SDL_Renderer* rendererobj;

    bool Running = true;
    bool FullscreenActive = false;

    window(const char* title, int w, int h);
    void pollevents(SDL_Event event);
    void destroy();
};

window::window(const char* title, int w, int h){
    windowobj = SDL_CreateWindow(title, w, h, SDL_WINDOW_BORDERLESS);

    rendererobj = SDL_CreateRenderer(windowobj, NULL);

    SDL_SetRenderLogicalPresentation(rendererobj, 1920, 1080, SDL_LOGICAL_PRESENTATION_STRETCH);
}

void window::pollevents(SDL_Event event){

    if (event.type == SDL_EVENT_QUIT){
        Running = false;
    } 

    if (event.type == SDL_EVENT_KEY_DOWN && event.key.scancode == SDL_SCANCODE_F11){
        FullscreenActive = !FullscreenActive;
        SDL_SetWindowFullscreen(windowobj, FullscreenActive);
    }

}

void window::destroy(){
    Running = false;
    SDL_DestroyWindow(windowobj);
    SDL_DestroyRenderer(rendererobj);
}