#include "GameModel.h"

GameModel::GameModel()
{
	generatorId = new IdGenerator();
	mouse = new GameObject();
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
	float *mouseCoord;
	mouseCoord[0] = mouseX;
	mouseCoord[1] = mouseY;
	mouse->setCoord(mouseCoord);
};

void GameModel::SetViewer(GameViewer* gViewer)
{
	this->gameViewer = gViewer;
};

void paintMouse(float x, float y)
{
	GameViewer.PaintObjMouse(mouse);

};