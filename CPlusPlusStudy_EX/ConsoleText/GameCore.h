#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace TextConsole
{
	class Position
	{
	public:

		int X;
		int Y;

		bool operator == (const Position& otherPos) const
		{
			return X == otherPos.X && Y == otherPos.Y;
		}
		bool operator != (const Position& otherPos) const
		{
			return !(*this == otherPos);
		}
	};

	enum ItemType
	{
		ItemType_BOOK = 0,
		ItemType_COIN,
		ItemType_SWORD,
		ItemType_KEY
	};

	class ItemData
	{
	public:
		ItemType Type;
		Position ItemPosition;
		int Quantity;
		char Icon;
		std::string Name;
	};

	struct LockedDoorData
	{
		Position DoorPosition;
	};

	class PlayerState
	{
	public:
		bool WantsToExit;               // ���� ����
		bool WantsDescription;          // ���� ����
		bool WantsInventoryListed;      // �κ��丮
		bool WantsToGet;                // ������ ȹ��
		int CurrentRoomIndex;           // �� ����
		Position CurrentPosition;       // �÷��̾� ��ġ
		Position NewPosition;           // ���� �̵� ��ġ
		std::vector<ItemData> Inventory;// ������ ����(���� �迭)
	};
	class MapData
	{
	public:
		std::string Name;
		std::string Description;
		std::string RoomMap;
		unsigned int RoomMapWidth;
		Position MapPosition;
		std::vector<ItemData> Inventory;
		std::vector<LockedDoorData> LockedDoor;
	};
	struct WorldState
	{
		std::vector<MapData> Rooms;
	};
	void InitializeGame(PlayerState& playerState, WorldState& worldState);
	void GetInput(PlayerState& playerState, const WorldState& worldState);
	void RenderGame(const PlayerState& playerState, const WorldState& worldState);
	void UpdateGame(PlayerState& playerState, WorldState& worldState);
	void CleanupGame(PlayerState& playerState, WorldState& worldState);
	void TryToUnlockDoors(PlayerState& playerState, MapData& currRoom);

	int PositionToIndex(const Position& position, int roomWidth);
	bool IsSpaceOutsideMap(const Position& position, const MapData& currRoom);
	bool IsSpaceOpenForMovement(const Position& position, const MapData& currRoom);
	char GetItemIcon(ItemType itemType);
	std::string GetItemName(ItemType itemType);
}