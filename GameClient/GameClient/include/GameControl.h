#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include "hge.h"

/*
	����� ���������� �� ���������� ������������� ����� (����������, ����, ������������ �������)
*/
class GameControl
{
public:
	GameControl(HGE* gEngine);
	~GameControl();
	bool FrameFunc();	//������� ������� ����������� ������� ��� ���������� �����
	void SetGameEngine(HGE* gEngine); //
protected:

private:
	HGE* gameEngine;
};

#endif