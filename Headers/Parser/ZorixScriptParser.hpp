#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "../UI/Buttons.hpp"
#include "ZorixScriptHelper.hpp"

struct ScriptParser
{
    int ObjectID;
    std::string BindType;
    std::string ScriptLocation;

    void* Object;

    ScriptParser(const char* NewScriptLocation);

    void ParseBindingType(const char* NameOfType);
    void ParseScript();
};

void SetObjectToKnownType(ScriptParser* Parser){
    if (Parser->BindType == "TextButton"){
        Parser->Object = AllTextButtons[Parser->ObjectID-1];
    }
}

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
                    BindType = std::string(NameOfType);
                    SetObjectToKnownType(this);
                }

            }

        }
        
    }
}

void ScriptParser::ParseScript(){
    std::ifstream Script(ScriptLocation);  
    std::string CurrentLine;

    bool EventActive = false;

    while (getline(Script, CurrentLine))
    {

        if (CurrentLine.find("onClick::(") != std::string::npos){
            handleOnClick(Object, Script, CurrentLine, this->BindType);
            EventActive = true;
        }

        if (CurrentLine == "::)" && EventActive == true){
            EventActive = false;
        }

        if (EventActive == true){
            continue;
        }

        handleSetBackgroundColor(Object, Script, CurrentLine, this->BindType);
        
        handleSetTextColor(Object, Script, CurrentLine, this->BindType);

        handleSetText(Object, Script, CurrentLine, this->BindType);

        handleSetPosition(Object, Script, CurrentLine, this->BindType);

        handleResize(Object, Script, CurrentLine, this->BindType);

    }

}

void ParseZorixScript(){
    
    ScriptParser Parser("test.zorixScript");

    Parser.ParseBindingType("TextButton");

    Parser.ParseScript();

}