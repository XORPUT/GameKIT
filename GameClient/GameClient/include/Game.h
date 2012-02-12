#ifndef GAME_H
#define GAME_H

#include <windows.h>
#include "MultiClassTunnel.h"

/*
	Самый главный класс в игре.
	Отвечает за создание инициализацию движка и запуск взаимодействия классов.
*/

class Game
{
public:
	void initEngine();	//Инициализация игрового движка HGE
	bool FrameFunc();	//Функция которая запускается движком при обновлении кадра
protected:

private:
	HGE *gameEngine;	//Игровой движок HGE
};



#endif