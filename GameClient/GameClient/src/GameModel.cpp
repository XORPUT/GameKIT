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


void GameModel::setMouseCoord(float mouseX, float mouseY)
{
	mouse = new GameObject();
	Point mouseCoord;
	mouseCoord.x = mouseX;
	mouseCoord.y = mouseY;
	mouse->setCoord(mouseCoord);
	mouse->setId(generatorId->GenerateId());
	mouse->setTexture("mouse.png");
	paintMouse();
	generatorId->FreeId(mouse->getId());
};

void GameModel::SetViewer(GameViewer* gViewer)
{
	this->gameViewer = gViewer;
};

void GameModel::paintMouse()
{
	gameViewer->PaintObjMouse(mouse);
};