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
	����� ����������� �������� �� ������
*/

class GameViewer
{
public:
	GameViewer(HGE *gEngine);
	~GameViewer();

	void SetGameEngine(HGE *gEngine); // �������� ��������� �� ������
	void PaintObj(GameObject *objId); // ��������� ������ �������
	void pushDataObj(std::vector<GameObject> objId, int countObjId); // �������� ������ �������� ��� ���������
protected:

private:
	HGE *gameEngine; // ��������� �� ������� ������
	std::vector<GameObject> arrayObjects; // ������ ��������
};

#endif