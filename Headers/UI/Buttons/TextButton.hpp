#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <curl/curl.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <sstream>

#include "../../ErrorHandling.hpp"

struct TextButton
{
    float x, y, w, h;
    std::string rendertext;
    
    SDL_Color ButtonColor;
    SDL_Color TextColor;

    SDL_Renderer* ButtonRenderer;
    TTF_Font* TextFont = TTF_OpenFont("Fonts/Arimo-VariableFont_wght.ttf", 24);

    int ObjectID;

    std::function<void()> Function;

    TextButton();

    // NOTE: n = new, so ny = new y :)
    void Init(SDL_Renderer* renderer, float nx, float ny, float nw, float nh, SDL_Color NewButtonColor, SDL_Color NewTextColor, const char* text);
    void handleFrame(bool ManageHover, SDL_Window* window);
    bool detectMouseHover(SDL_Window* window);
    void handleClick(SDL_Window* window);

    // NOTE: DSL Functions!
    void setBackgroundColor(int R, int G, int B);
    void setTextColor(int R, int G, int B);
    void setText(std::string Text);

    // NOTE: DSL Variables
    std::istringstream onClickStream;
};

int LASTTEXTBUTTONOBJECTID = -1;
std::vector<TextButton*> AllTextButtons;

TextButton::TextButton(){
    LASTTEXTBUTTONOBJECTID+=1;
    ObjectID = LASTTEXTBUTTONOBJECTID;
    AllTextButtons.push_back(this);
}

void TextButton::Init(SDL_Renderer* renderer, float nx, float ny, float nw, float nh, SDL_Color NewButtonColor, SDL_Color NewTextColor, const char* text){
    x = nx; y = ny; w = nw; h = nh;
    ButtonColor = NewButtonColor;
    TextColor = NewTextColor;
    ButtonRenderer = renderer;
    rendertext = std::string(text);
}

void TextButton::handleFrame(bool ManageHover, SDL_Window* window){
    SDL_FRect buttonrect = {x,y,w,h};

    Uint8 OldR, OldG, OldB, OldA;
    SDL_GetRenderDrawColor(ButtonRenderer, &OldR, &OldG, &OldB, &OldA);

    int HoverDarkenOffset = 35;

    if (ManageHover == true && window != nullptr){
        if (detectMouseHover(window) == true){
            SDL_SetRenderDrawColor(ButtonRenderer, std::abs(ButtonColor.r-HoverDarkenOffset), std::abs(ButtonColor.g-HoverDarkenOffset), std::abs(ButtonColor.b-HoverDarkenOffset), ButtonColor.a);
        } else {
            SDL_SetRenderDrawColor(ButtonRenderer, ButtonColor.r, ButtonColor.g, ButtonColor.b, ButtonColor.a);
        }
    } else {
        SDL_SetRenderDrawColor(ButtonRenderer, ButtonColor.r, ButtonColor.g, ButtonColor.b, ButtonColor.a);
    }
    
    SDL_RenderFillRect(ButtonRenderer, &buttonrect);
    SDL_SetRenderDrawColor(ButtonRenderer, OldR, OldG, OldB, OldA);

    SDL_FRect TextRect = {buttonrect.x+(buttonrect.w/4), buttonrect.y+(buttonrect.h/4), buttonrect.w/2, buttonrect.h/2};

    SDL_Surface* TextSurface = TTF_RenderText_Blended(TextFont, rendertext.c_str(), strlen(rendertext.c_str()), TextColor);
    SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(ButtonRenderer, TextSurface);

    SDL_SetTextureScaleMode(TextTexture, SDL_SCALEMODE_LINEAR);
    SDL_DestroySurface(TextSurface);

    SDL_RenderTexture(ButtonRenderer, TextTexture, NULL, &TextRect);

    handleClick(window);
}

bool TextButton::detectMouseHover(SDL_Window* window){
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

void TextButton::handleClick(SDL_Window* window){

    float mx, my;
    Uint32 mousestate = SDL_GetGlobalMouseState(&mx, &my);

    if (mousestate == SDL_BUTTON_MASK(SDL_BUTTON_LEFT)){
        if (detectMouseHover(window) == true){

            Function();
        }
    }

}

void TextButton::setBackgroundColor(int R, int G, int B){
    ButtonColor.r = R;
    ButtonColor.g = G;
    ButtonColor.b = B;
};

void TextButton::setTextColor(int R, int G, int B){
    TextColor.r = R;
    TextColor.g = G;
    TextColor.b = B;
}

void TextButton::setText(std::string Text){
    rendertext = Text;
}