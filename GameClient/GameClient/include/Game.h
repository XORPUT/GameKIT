#ifndef GAME_H
#define GAME_H

#include <windows.h>

#include "GameModel.h"
#include "GameViewer.h"
#include "GameControl.h"
#include "GameNetwork.h"
#include "GameSetting.h"
#include "MultiClassTunnel.h"


/*
	Самый главный класс в игре.
	Отвечает за создание инициализацию движка и запуск взаимодействия классов.
*/

class Game
{
public:
	void initGame();	//Инициализация игры
	bool FrameFunc();	//Функция которая запускается движком при обновлении кадра
protected:

private:
	void initEngine();	//Инициализация игрового движка HGE

	HGE *gameEngine;	//Игровой движок HGE

	GameSetting *gameSetting;	//Базовый блок "Конфигурация игры"
	GameModel *gameModel;		//Базовый блок "Модель"
	//Раскомменить когда будет написан класс//			GameViewer *gameViewer;		//Базовый блок "Вид"
	GameControl *gameControl;	//Базовый блок "Контроль"
	GameNetwork *gameNetwork;	//Базовый блок "Сеть"
	MultiClassTunnel *multiClassTunnel;		//Межклассовый шлюз
};



#endif