#ifndef GAMEGETDATAOBJ_H
#define GAMEGETDATAOBJ_H

#include "GameObject.h"
#include "GameObject_Player.h"
#include "vector"

/*
	Получение countId количества ID для отрисовки
*/

class GameGetDataObj
{
public:
	void pushDataObj(std::vector<GameObject> objId, int countObjId); // Получает список объектов для отрисовки
protected:

private:

};

#endif