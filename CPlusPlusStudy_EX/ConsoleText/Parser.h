#pragma once
#include <string>

enum CommandType // � ������ Ŀ�ǵ����� �����ϴ� ������(enum)
{
	CommandTypeNone,

	CommandTypeNorth,
	CommandTypeSouth,
	CommandTypeEast,
	CommandTypeWest,

	CommandTypeQuit,
	CommandTypeGet,
	CommandTypeInventory,
	CommandTypeHelp,
	CommandTypeInfo,

	// �� �� ������Ʈ �� ����
};

// char* char[]
// c++ string Ŭ����
// TypeString string == "W"	 => CommandTypeNorth


class ConsoleTextCommand
{
public:
	CommandType commandType;
	std::string Parameter;	   // ���� �Է¹��� ���� ������ "W" => commandType�� CommandTypeNorth
};

ConsoleTextCommand ParseCommand();
