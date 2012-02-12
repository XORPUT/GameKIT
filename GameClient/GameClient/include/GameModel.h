#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>

#include "GameViewer.h"
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
	bool FrameFunc();	//Функция которая запускается движком при обновлении кадра


	/************************************************************************/
	/* Взаимодействие с "Контролем"                                         */
	void setMouseCoord(float mouseX, float mouseY);	//Установить текущие координаты мыши
	/************************************************************************/

	/************************************************************************/
	/* Взаимодействие с "Видом"                                             */
	void SetViewer(GameViewer* gViewer);	//Установить Viewer
	/************************************************************************/

	void paintSendListObject(std::vector<GameObject> sendList);	//Отправка на отрисовку списока объектов

protected:

private:
	GameViewer *gameViewer;


	IdGenerator *generatorId;	//Генератор Id для объектов
	std::vector<GameObject_Player> players;	//Игроки

	std::vector<GameObject> *sendListObject;	//Список объектов для отправки
	GameObject *mouse;	//Мышка игрока
};







#endif