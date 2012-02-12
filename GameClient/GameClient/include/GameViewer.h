#ifndef GAMEVIEWER_H
#define GAMEVIEWER_H

#include "hge.h"
#include "GameObject.h"
#include "hgefont.h"
#include "hgesprite.h"
#include "Point.h"
#include "sprObject.h"
#include "vector"

/*
	Класс отображение объектов на экране
*/

class GameViewer
{
public:
	GameViewer(HGE *gEngine);
	~GameViewer();

	void SetGameEngine(HGE *gEngine); // Принятие указателя на движок
	void PaintObj(GameObject *objId); // Отрисовка одного объекта
	void PushDataObj(std::vector<GameObject> objId); // Получает список объектов для отрисовки
protected:

private:
	HGE *gameEngine; // Указатель на игровой движок
	std::vector<GameObject> arrayObjects; // Массив объектов
};

#endif