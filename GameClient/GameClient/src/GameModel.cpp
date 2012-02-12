#include "GameModel.h"

GameModel::GameModel()
{
	generatorId = new IdGenerator();
	sendListObject = new std::vector<GameObject>();
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


void GameModel::setMouseCoord(float mouseX, float mouseY)
{
	
};

void GameModel::SetViewer(GameViewer* gViewer)
{
	this->gameViewer = gViewer;
};

void GameModel::paintSendListObject(std::vector<GameObject> *sendList)
{
	gameViewer->PushDataObj(sendList);
};