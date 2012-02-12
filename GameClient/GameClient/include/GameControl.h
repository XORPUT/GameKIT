#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include "hge.h"
#include "GameModel.h"

/*
	Класс отвечающий за управление пользователем игрой (клавиатура, мышь, интерфейсные события)
*/
class GameControl
{
public:
	GameControl(HGE* gEngine);
	~GameControl();
	bool FrameFunc();	//Функция, которая запускается движком при обновлении кадра
	void SetGameEngine(HGE* gEngine); // Принимает указаьтель на движок
	void SetModel (GameModel* gModel); //Принимает указатель на модель
protected:

private:
	HGE* gameEngine;
	GameModel* gameModel;
};

#endif