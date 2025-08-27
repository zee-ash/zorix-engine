#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <curl/curl.h>

#include "WindowEssentials.hpp"
#include "ErrorHandling.hpp"
#include "Engine.hpp"

#include "UI/Buttons.hpp"

void NewProject(){
    window NewProjectWindow("Zorix - New project", 1280, 720);

    while (NewProjectWindow.Running == true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            NewProjectWindow.pollevents(event);
        }

        SDL_RenderClear(NewProjectWindow.rendererobj);
        SDL_SetRenderDrawColor(NewProjectWindow.rendererobj, 60,60,60,255);

        SDL_RenderPresent(NewProjectWindow.rendererobj);
        SDL_Delay(16);
    }
    
    NewProjectWindow.destroy();

    return;
};