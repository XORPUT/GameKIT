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

void GameModel::GenerateSendListObjects()
{
	sendListObject->clear();
	//sendListObject->push_back(players);
	//sendListObject->push_back(mobs);


	//****************ÁËÎÊ ÄËß ÒÅÑÒÀ. ÓÄÀËÈÒÜ!!!!!!!!!!!
	/*
	GameObject *fon = new GameObject();
	fon->setId( generatorId->GenerateId() );
	Point p;
	p.x = 0;
	p.y = 0;
	fon->setCoord(p);
	fon->setTexture("fon.jpg");

	sendListObject->push_back(*fon);
	delete fon;

	GameObject *player = new GameObject();
	player->setId( generatorId->GenerateId() );
	Point p2;
	p2.x = 50;
	p2.y = 50;
	player->setCoord(p2);
	player->setTexture("player.png");

	sendListObject->push_back(*player);
	delete player;
	
	GameObject *mob = new GameObject();
	mob->setId( generatorId->GenerateId() );
	Point p4;
	p4.x = 100;
	p4.y = 100;
	mob->setCoord(p4);
	mob->setTexture("zombie.png");

	sendListObject->push_back(*mob);
	delete mob;
	
	GameObject *cursor = new GameObject();
	cursor->setId( generatorId->GenerateId() );
	Point p3;
	p3 = mouse.getCoord();
	
	cursor->setCoord(p3);
	cursor->setTexture("cursor.png");

	sendListObject->push_back(*cursor);
	delete cursor;
	*/
};

bool GameModel::FrameFunc()
{
	injectSendListObjectToViewer();
	GenerateSendListObjects();
	return false;
};


void GameModel::setMouseCoord(float mouseX, float mouseY)
{
	Point coord;	//Êîîðäèíàòû ìûøè
	coord.x = mouseX;
	coord.y = mouseY;
	mouse.setCoord(coord);
};

void GameModel::SetViewer(GameViewer* gViewer)
{
	this->gameViewer = gViewer;
};

void GameModel::injectSendListObjectToViewer()
{
	gameViewer->PushDataObj(sendListObject);
};