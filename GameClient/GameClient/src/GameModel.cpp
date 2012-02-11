#include "GameModel.h"

GameModel::GameModel()
{
	generatorId = new IdGenerator();
};

GameModel::~GameModel()
{

};

int GameModel::AddPlayer()
{
	GameObject_Player *newPlayer = new GameObject_Player();
	//ÄÎÏÈÑÀÒÜ ÔÓÍÊÖÈÞ!!!!!!!!!!!!!!!!!!!!!!!!!
	return newPlayer->getId();
};