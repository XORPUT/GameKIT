#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "GameObject.h"
#include "IdGenerator.h"

#include "GameObject_Player.h"

/*
	Базовый класс функционального блока Модель
*/
class GameModel
{
public:
	GameModel();
	~GameModel();

protected:

private:
	IdGenerator *generatorId;
	GameObject_Player *player1;
};







#endif