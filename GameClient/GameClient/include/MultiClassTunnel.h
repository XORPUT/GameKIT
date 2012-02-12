#ifndef MULTICLASSTUNNEL_H
#define MULTICLASSTUNNEL_H

#include "GameModel.h"
#include "GameViewer.h"
#include "GameControl.h"
#include "GameNetwork.h"
#include "GameSetting.h"


/*
	Класс, отвечающий за межклассовое взаимодействие
*/

class MultiClassTunnel
{
public:
	MultiClassTunnel();
	~MultiClassTunnel();
	bool FrameFunc();	//Функция которая запускается движком при обновлении кадра
protected:

private:
	GameSetting *gameSetting;
	GameModel *gameModel;
	GameControl *gameControl;
	GameNetwork *gameNetwork;
	
	/*	Раскомментить когда будут созданы классы
	GameViewer *gameViewer;
	*/
};






#endif