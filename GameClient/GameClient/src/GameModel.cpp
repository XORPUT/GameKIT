#include "GameModel.h"

GameModel::GameModel()
{
	generatorId = new IdGenerator();
};

GameModel::~GameModel()
{

};

int GameModel::addPlayer()
{
	GameObject_Player *newPlayer = new GameObject_Player();
	newPlayer->setId( generatorId->GenerateId() );
	return newPlayer->getId();
};

void GameModel::deletePlayer(GameObject_Player *player)
{
	generatorId->FreeId( player->getId() );
	delete player;
};

bool GameModel::FrameFunc()
{
	return false;
};


void GameModel::getMouseCoord(float mouseX, float mouseY)
{
	mouseCoordX = mouseX;
	mouseCoordY = mouseY;
};