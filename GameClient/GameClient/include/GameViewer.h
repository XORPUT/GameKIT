#ifndef GAMEVIEWER_H
#define GAMEVIEWER_H

#include "hge.h"

/*
	����� ���������� ������������ �� ������
*/

class GameViewer
{
public:
	GameViewer(HGE *gEngine);
	~GameViewer();

	void SetGameEngine(HGE *gEngine); // �������� ��������� �� ������
protected:

private:
	HGE *gameEngine;  // ��������� �� ������� ������
};

#endif