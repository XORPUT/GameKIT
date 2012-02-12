#ifndef GAMEVIEWER_H
#define GAMEVIEWER_H

#include "hge.h"
#include "GameObject.h"

/*
	����� ����������� �������� �� ������
*/

class GameViewer
{
public:
	GameViewer(HGE *gEngine);
	~GameViewer();

	void SetGameEngine(HGE *gEngine); // �������� ��������� �� ������
	void PaintOneObj(GameObject *objId); // ��������� ������ �������
	void PaintObjMouse(GameObject *objId); // ��������� ������� "����"
protected:

private:
	HGE *gameEngine; // ��������� �� ������� ������
};

#endif