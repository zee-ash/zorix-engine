#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>

#include "../UI/Buttons.hpp"
#include "ZorixScriptParser.hpp"

void handleSetBackgroundColor(void* Object, std::istream& Script, std::string CurrentLine, std::string BindType){
    
    if (CurrentLine.find("setBackgroundColor(") != std::string::npos){
        getline(Script, CurrentLine);
        int R = std::stoi(CurrentLine);

        getline(Script, CurrentLine);
        int G = std::stoi(CurrentLine);

        getline(Script, CurrentLine);
        int B = std::stoi(CurrentLine);

        if (BindType == "TextButton"){ static_cast<TextButton*>(Object)->setBackgroundColor(R, G, B); };
    }

}

void handleSetTextColor(void* Object, std::istream& Script, std::string CurrentLine, std::string BindType){

    if (CurrentLine.find("setTextColor(") != std::string::npos){
        getline(Script, CurrentLine);
        int R = std::stoi(CurrentLine);

        getline(Script, CurrentLine);
        int G = std::stoi(CurrentLine);

        getline(Script, CurrentLine);
        int B = std::stoi(CurrentLine);
        
        if (BindType == "TextButton"){ static_cast<TextButton*>(Object)->setTextColor(R, G, B); };
    }

}

void handleSetText(void* Object, std::istream& Script, std::string CurrentLine, std::string BindType){

    if (CurrentLine.find("setText(") != std::string::npos){
        getline(Script, CurrentLine);
        CurrentLine.pop_back();
        CurrentLine = CurrentLine.substr(1);

        if (BindType == "TextButton"){ static_cast<TextButton*>(Object)->setText(CurrentLine); };
    }

}

void handleSetPosition(void* Object, std::istream& Script, std::string CurrentLine, std::string BindType){

    if (CurrentLine.find("setPosition(") != std::string::npos){
        getline(Script, CurrentLine);
        int x = std::stoi(CurrentLine);

        getline(Script, CurrentLine);
        int y = std::stoi(CurrentLine);

        if (BindType == "TextButton"){ static_cast<TextButton*>(Object)->x = x; static_cast<TextButton*>(Object)->y = y; };
    }

}

void handleResize(void* Object, std::istream& Script, std::string CurrentLine, std::string BindType){

    if (CurrentLine.find("resize(") != std::string::npos){
        getline(Script, CurrentLine);
        int w = std::stoi(CurrentLine);

        getline(Script, CurrentLine);
        int h = std::stoi(CurrentLine);

        if (BindType == "TextButton"){ static_cast<TextButton*>(Object)->w = w; static_cast<TextButton*>(Object)->h = h; };
    }

}

void handleOnClick(void* Object, std::istream& Script, std::string CurrentLine, std::string BindType){

    if (BindType == "TextButton"){

        TextButton* button = static_cast<TextButton*>(Object);
        std::string PreserveString;

        while (getline(Script, CurrentLine))
        {
            if (CurrentLine == "::)"){
                break;
            }

            PreserveString += (CurrentLine += "\n");
        }

        std::istringstream ScriptFromString(PreserveString);
        button->onClickStream.str(PreserveString);

        button->Function = [button, SafeBindType = BindType]() {
            
            std::string NextLine;
            
            while (getline(button->onClickStream, NextLine))
            {
                handleSetBackgroundColor(button, button->onClickStream, NextLine, SafeBindType);
                handleSetTextColor(button, button->onClickStream, NextLine, SafeBindType);
                handleSetText(button, button->onClickStream, NextLine, SafeBindType);
                handleSetPosition(button, button->onClickStream, NextLine, SafeBindType);
                handleResize(button, button->onClickStream, NextLine, SafeBindType);
            }

        };

    };
    
}