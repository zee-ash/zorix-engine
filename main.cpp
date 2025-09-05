#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <curl/curl.h>

#include "Headers/WindowEssentials.hpp"
#include "Headers/ErrorHandling.hpp"
#include "Headers/Engine.hpp"

#include "Headers/UI/Buttons.hpp"

#include "Headers/Parser/ZorixScriptParser.hpp"

int main(){

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO);
    TTF_Init();

    window mainWindow("Zorix-Reformed (Alpha 1.1)", 1280, 720);

    TextButton NewProjectButton;
    NewProjectButton.Init(mainWindow.rendererobj, (1920/2)-100, (1920/2)-(75/2), 250, 70, {40,40,40,255}, {255,255,255,255}, "New Project");

    NewProjectButton.Function = [&mainWindow](){
        mainWindow.destroy();
        NewProject();
    };

    while (mainWindow.Running == true)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            mainWindow.pollevents(event);
        }
        
        SDL_RenderClear(mainWindow.rendererobj);
        SDL_SetRenderDrawColor(mainWindow.rendererobj, 80,80,80,255);

        NewProjectButton.handleFrame(true, mainWindow.windowobj);
        
        SDL_RenderPresent(mainWindow.rendererobj);
        SDL_Delay(16);
    }

    TTF_Quit();
    SDL_Quit();
    return -1;
}