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
	bool frameStarted();	//Вызывается когда начинается новый frame(кадр)
	bool FrameFunc();	//Функция которая запускается движком при обновлении кадра


	/************************************************************************/
	/* Взаимодействие с "Контролем"                                         */
	/************************************************************************/
	void setMouseCoord(float mouseX, float mouseY);
protected:

private:
	IdGenerator *generatorId;	//Генератор Id для объектов
	std::vector<GameObject_Player> players;	//Игроки

	float mouseCoordX, mouseCoordY;
};







#endif