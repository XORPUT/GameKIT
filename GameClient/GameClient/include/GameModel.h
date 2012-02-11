#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>

#include "GameObject.h"
#include "GameGetDataObj.h"

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
	int AddPlayer();	//Добавляет игрока, возвращает его идентификатор
protected:

private:
	IdGenerator *generatorId;
	std::vector<GameObject_Player> players;

};







#endif