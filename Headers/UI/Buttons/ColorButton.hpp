#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <curl/curl.h>
#include <algorithm>
#include <functional>

#include "../../ErrorHandling.hpp"

struct ColorButton
{
    float x, y, w, h;

    SDL_Color ButtonColor;

    SDL_Renderer* ButtonRenderer;
    TTF_Font* TextFont = TTF_OpenFont("Fonts/Arimo-VariableFont_wght.ttf", 20);

    std::function<void()> Function;

    // NOTE: n = new, so ny = new y :)
    ColorButton(SDL_Renderer* renderer, float nx, float ny, float nw, float nh, SDL_Color NewButtonColor);

    void handleFrame(bool ManageHover, SDL_Window* window);
    bool detectMouseHover(SDL_Window* window);
    void handleClick(SDL_Window* window);
};

ColorButton::ColorButton(SDL_Renderer* renderer, float nx, float ny, float nw, float nh, SDL_Color NewButtonColor){
    x = nx; y = ny; w = nw; h = nh;
    ButtonColor = NewButtonColor;
    ButtonRenderer = renderer;
}

void ColorButton::handleFrame(bool ManageHover, SDL_Window* window){
    SDL_FRect buttonrect = {x,y,w,h};

    Uint8 OldR, OldG, OldB, OldA;
    SDL_GetRenderDrawColor(ButtonRenderer, &OldR, &OldG, &OldB, &OldA);

    int HoverDarkenOffset = 35;

    if (ManageHover == true && window != nullptr){
        if (detectMouseHover(window) == true){
            SDL_SetRenderDrawColor(ButtonRenderer, std::abs(ButtonColor.r-HoverDarkenOffset), std::abs(ButtonColor.g-HoverDarkenOffset), std::abs(ButtonColor.b-HoverDarkenOffset), 255);
        } else {
            SDL_SetRenderDrawColor(ButtonRenderer, ButtonColor.r, ButtonColor.g, ButtonColor.b, 255);
        }
    } else {
        SDL_SetRenderDrawColor(ButtonRenderer, ButtonColor.r, ButtonColor.g, ButtonColor.b, 255);
    }
    
    SDL_RenderFillRect(ButtonRenderer, &buttonrect);
    SDL_SetRenderDrawColor(ButtonRenderer, OldR, OldG, OldB, OldA);

    handleClick(window);
}

bool ColorButton::detectMouseHover(SDL_Window* window){
    float mx, my;
    SDL_GetMouseState(&mx, &my);

    int ww, wh;
    SDL_GetWindowSizeInPixels(window, &ww, &wh);

    mx *= (1920/float(ww));
    my *= (1080/float(wh));

    if (mx > x && mx < x+w && my > y && my < y+h){
        return true;
    }

    return false;
}

void ColorButton::handleClick(SDL_Window* window){

    float mx, my;
    Uint32 mousestate = SDL_GetMouseState(&mx, &my);

    if (mousestate == SDL_BUTTON_MASK(SDL_BUTTON_LEFT)){
        if (detectMouseHover(window) == true){
            Function();
        }
    }

}