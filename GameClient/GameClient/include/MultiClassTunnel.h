#ifndef MULTICLASSTUNNEL_H
#define MULTICLASSTUNNEL_H

#include "GameModel.h"
#include "GameViewer.h"
#include "GameControl.h"
#include "GameNetwork.h"
#include "GameSetting.h"


/*
	Класс, отвечающий за межклассовое взаимодействие (шлюз)
*/

class MultiClassTunnel
{
public:
	MultiClassTunnel(GameSetting *gSetting, GameModel *gModel, GameControl *gControl, GameNetwork *gNetwork);
	~MultiClassTunnel();
	
	void Init(GameSetting *gSetting, GameModel *gModel, GameControl *gControl, GameNetwork *gNetwork);	//Инициализация шлюза
	bool FrameFunc();	//Функция которая запускается движком при обновлении кадра
protected:

private:
	GameSetting *gameSetting;	//Базовый блок "Конфигурация игры"
	GameModel *gameModel;		//Базовый блок "Модель"
	/*	Раскомментить когда будут созданы классы
	GameViewer *gameViewer;
	*/
	GameControl *gameControl;	//Базовый блок "Контроль"
	GameNetwork *gameNetwork;	//Базовый блок "Сеть"
};






#endif