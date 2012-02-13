#include "GameModel.h"

GameModel::GameModel()
{
	generatorId = new IdGenerator();
	sendListObject = new std::vector<GameObject>();
	players = new std::vector<GameObject_Player>();
	mobs = new std::vector<GameObject_Mob>();
};

GameModel::~GameModel()
{
	delete generatorId;
	delete sendListObject;
	delete players;
	delete mobs;
};

int GameModel::addPlayer()
{
	GameObject_Player *newPlayer = new GameObject_Player();
	newPlayer->setId( generatorId->GenerateId() );
	return newPlayer->getId();
};

int GameModel::addMob()
{
	GameObject_Mob *newMob = new GameObject_Mob();
	newMob->setId( generatorId->GenerateId() );
	return newMob->getId();
};

void GameModel::deletePlayer(GameObject_Player *player)
{
	generatorId->FreeId( player->getId() );
	delete player;
};

void GameModel::deleteMob(GameObject_Mob *mob)
{
	generatorId->FreeId( mob->getId() );
	delete mob;
};

bool GameModel::FrameFunc()
{
	return false;
};


void GameModel::setMouseCoord(float mouseX, float mouseY)
{
	Point coord;	//Координаты мыши
	coord.x = mouseX;
	coord.y = mouseY;
	mouse.setCoord(coord);
};

void GameModel::SetViewer(GameViewer* gViewer)
{
	this->gameViewer = gViewer;
};

void GameModel::paintSendListObject(std::vector<GameObject> *sendList)
{
	gameViewer->PushDataObj(sendList);
};