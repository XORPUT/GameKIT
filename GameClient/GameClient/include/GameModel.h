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
	int addPlayer();	//Добавляет игрока, возвращает его идентификатор
	void deletePlayer(GameObject_Player *player);	//Удаляет игрока
protected:

private:
	IdGenerator *generatorId;	//Генератор Id для объектов
	std::vector<GameObject_Player> players;	//Игроки

};







#endif