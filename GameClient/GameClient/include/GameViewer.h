#ifndef GAMEVIEWER_H
#define GAMEVIEWER_H

#include "hge.h"

/*
	Класс управления отображением на экране
*/

class GameViewer
{
public:
	GameViewer(HGE *gEngine);
	~GameViewer();

	void SetGameEngine(HGE *gEngine); // Принятие указателя на движок
protected:

private:
	HGE *gameEngine;  // Указатель на игровой движок
};

#endif