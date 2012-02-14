#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	
	bool FrameFunc();	//Функция которая запускается движком при обновлении кадра
	void injectSendListObjectToViewer();	//Передаёт указатель на список объектов для отрисовки Вьюверу
	
	int CreatePlayer(Point coordPlayer, std::string texturePlayer);	//Создаёт игрока, возвращает его идентификатор
	int addMob(Point coordMob, std::string textureMob);	//Добавляет моба, возвращает его идентификатор
	void deletePlayer(GameObject_Player *player);	//Удаляет игрока
	void deleteMob(GameObject_Mob *mob);	//Удаляет моба
	void GenerateSendListObjects();


	/************************************************************************/
	/* Взаимодействие с "Контролем"                                         */
	void setMouseCoord(float mouseX, float mouseY);	//Установить текущие координаты мыши
	/************************************************************************/

	/************************************************************************/
	/* Взаимодействие с "Видом"                                             */
	void SetViewer(GameViewer* gViewer);	//Установить Viewer
	void paintSendListObject(std::vector<GameObject> *sendList);	//Отправка на отрисовку списока объектов
	/************************************************************************/

protected:

private:
	GameViewer *gameViewer;

	IdGenerator *generatorId;	//Генератор Id для объектов
	std::vector<GameObject_Mob> *mobs;	//Список мобов
	std::vector<GameObject> *sendListObject;	//Список объектов для отправки

	GameObject_Player player;	//Игрок
	GameObject mouse;	//Мышка игрока
};







#endif