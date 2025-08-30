#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <any>
#include <curl/curl.h>

#include "WindowEssentials.hpp"
#include "ErrorHandling.hpp"
#include "Engine.hpp"

#include "UI/Buttons.hpp"

#include "ZorixScriptParser.hpp"

std::any AllClassesWindowfunction(){

    window ClassesWindow("Pick a class", 500, 800);
    SDL_WindowID ClassesWindowID = SDL_GetWindowID(ClassesWindow.windowobj);

    std::any result;

    while (ClassesWindow.Running == true)
    {
        SDL_Event event;

        // 40 per character

        TextButton ColorButtonClass_Button;
        ColorButtonClass_Button.Init(ClassesWindow.rendererobj, 30, 15, 40*11, 50, {80, 80, 80}, {255, 255, 255}, "Color Button");

        ColorButtonClass_Button.Function = [&ColorButtonClass_Button, &result, &ClassesWindow](){
            result = ColorButton();
            ClassesWindow.Running = false;
        };
        
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == ClassesWindowID){
                ClassesWindow.Running = false;
            }
        }

        SDL_SetRenderDrawColor(ClassesWindow.rendererobj, 60,60,60,255);
        SDL_RenderClear(ClassesWindow.rendererobj);

        ColorButtonClass_Button.handleFrame(true, ClassesWindow.windowobj);

        SDL_RenderPresent(ClassesWindow.rendererobj);
        SDL_Delay(16);
    }

    ClassesWindow.destroy();

    return result;
}

void NewProject(){
    window NewProjectWindow("Zorix - New project", 1280, 720);

    std::vector<ColorButton> ColorButtons;

    TextButton AddClassButton;
    AddClassButton.Init(NewProjectWindow.rendererobj, 1920-60, 10, 50, 50, {80, 80, 80}, {255, 255, 255}, "+");

    AddClassButton.Function = [&ColorButtons, &NewProjectWindow](){
        std::any ClassChosen = AllClassesWindowfunction();
        if (std::any_cast<ColorButton>(&ClassChosen)){
            ColorButton DefaultButton;
            DefaultButton.Init(NewProjectWindow.rendererobj, 0, 0, 200, 100, {255, 255, 255});
            DefaultButton.Function = [](){
                // blank init :d
            };
            ColorButtons.push_back(DefaultButton);
        }
    };

    ParseZorixScript();

    while (NewProjectWindow.Running == true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            NewProjectWindow.pollevents(event);
        }

        SDL_RenderClear(NewProjectWindow.rendererobj);
        SDL_SetRenderDrawColor(NewProjectWindow.rendererobj, 60,60,60,255);

        AddClassButton.handleFrame(true, NewProjectWindow.windowobj);

        for (int i = 0; i < ColorButtons.size(); i++){
            ColorButtons[i].handleFrame(true, NewProjectWindow.windowobj);
        }

        SDL_RenderPresent(NewProjectWindow.rendererobj);
        SDL_Delay(16);
    }
    
    NewProjectWindow.destroy();

    return;
};