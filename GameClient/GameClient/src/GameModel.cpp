#include "GameModel.h"

GameModel::GameModel()
{
	generatorId = new IdGenerator();
	player1 = new GameObject_Player();
	player1->Init( generatorId->GenerateId() );
	int idPlayer = player1->getId();
};

GameModel::~GameModel()
{

};