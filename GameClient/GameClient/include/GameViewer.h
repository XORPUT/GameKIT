#ifndef GAMEVIEWER_H
#define GAMEVIEWER_H

#include "hge.h"
#include "GameObject.h"

/*
	Класс отображение объектов на экране
*/

class GameViewer
{
public:
	GameViewer(HGE *gEngine);
	~GameViewer();

	void SetGameEngine(HGE *gEngine); // Принятие указателя на движок
	void PaintOneObj(GameObject *objId); // Отрисовка одного объекта
	void PaintObjMouse(GameObject *objId); // Отрисовка объекта "мыши"
protected:

private:
	HGE *gameEngine; // Указатель на игровой движок
};

#endif