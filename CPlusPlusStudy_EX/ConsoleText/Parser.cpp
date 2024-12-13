#include "Parser.h"
#include <vector>   // �����迭 (ũ�� ������ ������ �迭)
#include <iostream>

ConsoleTextCommand ParseCommand()
{
    ConsoleTextCommand command = {};
    command.commandType = CommandTypeNone;

    const unsigned int INPUTCHARLIMIT = 256; // ����� �ִ� ũ�⸦ ����
    char inputstr[INPUTCHARLIMIT];

    char* inputValue = fgets(inputstr, INPUTCHARLIMIT, stdin); // W, North, Up
   
    std::vector<std::string> tokens;
    char* nextToken = nullptr;
    char* token = strtok_s(inputstr, "\t\n", &nextToken);
    // strtoken : ���ڿ��� ������seperator
    
    while (token)
    {
        tokens.push_back(token);
        token = strtok_s(nullptr, " \t\n", &nextToken);
    }

    // north south 

    if (tokens.size() >= 1) // �Է��� ���� ���
    {
        std::string parseData = tokens[0];

        // ���� -> ��ҹ���. UP up Up uP   => ���δ� up ��ȯ�Ǵ� ���
        for (unsigned int i = 0; i < parseData.size(); i++)
        {
            parseData[i] = tolower(parseData[i]);
        }

        if (parseData == "w" || parseData == "north" || parseData == "up")
        {
            command.commandType = CommandTypeNorth;
        }
        else if (parseData == "s" || parseData == "south" || parseData == "down")
        {
            command.commandType = CommandTypeSouth;
        }
        else if (parseData == "a" || parseData == "west" || parseData == "left")
        {
            command.commandType = CommandTypeWest;
        }
        else if (parseData == "d" || parseData == "east" || parseData == "right")
        {
            command.commandType = CommandTypeEast;
        }
    }


    return command;
}
