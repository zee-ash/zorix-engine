#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "UI/Buttons.hpp"
struct ScriptParser
{
    int ObjectID;
    std::string ParentType;
    std::string ScriptLocation;

    ScriptParser(const char* NewScriptLocation);

    void ParseBindingType(const char* NameOfType);

    void ParseTextButton();
};

ScriptParser::ScriptParser(const char* NewScriptLocation){
    ScriptLocation = std::string(NewScriptLocation);
}

void ScriptParser::ParseBindingType(const char* NameOfType){
    std::string CurrentLine;
    std::ifstream zorixScript(ScriptLocation);
    
    while (getline(zorixScript, CurrentLine))
    {

        if (CurrentLine == "bind("){
            getline(zorixScript, CurrentLine);

            if (CurrentLine.find(R"(Type: ")" + std::string(NameOfType) + R"(")") != std::string::npos){

                getline(zorixScript, CurrentLine);

                if (CurrentLine.find("Id: ") != std::string::npos){
                    ObjectID = std::stoi(CurrentLine.substr(strlen("Id: ")));
                    ParentType = std::string(NameOfType);
                }

            }

        }

        
    }
}

void ScriptParser::ParseTextButton(){
    std::ifstream Script(ScriptLocation);  
    std::string CurrentLine;

    while (getline(Script, CurrentLine))
    {
        
        if (CurrentLine.find("setBackgroundColor(") != std::string::npos){
            getline(Script, CurrentLine);
            int R = std::stoi(CurrentLine);

            getline(Script, CurrentLine);
            int G = std::stoi(CurrentLine);

            getline(Script, CurrentLine);
            int B = std::stoi(CurrentLine);

            AllTextButtons[ObjectID-1]->ButtonColor.r = R;
            AllTextButtons[ObjectID-1]->ButtonColor.g = G;
            AllTextButtons[ObjectID-1]->ButtonColor.b = B;
        }

        if (CurrentLine.find("setTextColor(") != std::string::npos){
            getline(Script, CurrentLine);
            int R = std::stoi(CurrentLine);

            getline(Script, CurrentLine);
            int G = std::stoi(CurrentLine);

            getline(Script, CurrentLine);
            int B = std::stoi(CurrentLine);

            AllTextButtons[ObjectID-1]->TextColor.r = R;
            AllTextButtons[ObjectID-1]->TextColor.g = G;
            AllTextButtons[ObjectID-1]->TextColor.b = B;
        }

        if (CurrentLine.find("setText(") != std::string::npos){
            getline(Script, CurrentLine);
            CurrentLine.pop_back();
            CurrentLine = CurrentLine.substr(1);

            AllTextButtons[ObjectID-1]->rendertext = CurrentLine;
        }

        if (CurrentLine.find("setPosition(") != std::string::npos){
            getline(Script, CurrentLine);
            int x = std::stoi(CurrentLine);

            getline(Script, CurrentLine);
            int y = std::stoi(CurrentLine);

            AllTextButtons[ObjectID-1]->x = x;
            AllTextButtons[ObjectID-1]->y = y;
        }

        if (CurrentLine.find("resize(") != std::string::npos){
            getline(Script, CurrentLine);
            int w = std::stoi(CurrentLine);

            getline(Script, CurrentLine);
            int h = std::stoi(CurrentLine);

            AllTextButtons[ObjectID-1]->w = w;
            AllTextButtons[ObjectID-1]->h = h;
        }

    }

}

void ParseZorixScript(){
    
    ScriptParser Parser("test.zorixScript");

    Parser.ParseBindingType("TextButton");

    if (Parser.ParentType == "TextButton"){
        if (AllTextButtons[Parser.ObjectID-1]){

            Parser.ParseTextButton();

            AllTextButtons[Parser.ObjectID-1]->Function = [](){
                
            };

        }
    }

}