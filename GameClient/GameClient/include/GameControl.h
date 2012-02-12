#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include "hge.h"
#include "GameModel.h"

/*
	����� ���������� �� ���������� ������������� ����� (����������, ����, ������������ �������)
*/
class GameControl
{
public:
	GameControl(HGE* gEngine);
	~GameControl();
	bool FrameFunc();	//�������, ������� ����������� ������� ��� ���������� �����
	void SetGameEngine(HGE* gEngine); // ��������� ���������� �� ������
	void SetModel (GameModel* gModel); //��������� ��������� �� ������
protected:

private:
	HGE* gameEngine;
	GameModel* gameModel;
};

#endif