#ifndef GAME_H
#define GAME_H

#include <windows.h>

#include "GameModel.h"
#include "GameViewer.h"
#include "GameControl.h"
#include "GameNetwork.h"
#include "GameSetting.h"
#include "MultiClassTunnel.h"


/*
	����� ������� ����� � ����.
	�������� �� �������� ������������� ������ � ������ �������������� �������.
*/

class Game
{
public:
	void initGame();	//������������� ����
	void destroyGame();	//�������� ����
	bool FrameFunc();	//������� ������� ����������� ������� ��� ���������� �����
protected:

private:
	void initEngine();	//������������� �������� ������ HGE
	void releaseEngine();	//���������� ������ �������� ������ HGE

	HGE *gameEngine;	//������� ������ HGE

	GameSetting *gameSetting;	//������� ���� "������������ ����"
	GameModel *gameModel;		//������� ���� "������"
	GameViewer *gameViewer;		//������� ���� "���"
	GameControl *gameControl;	//������� ���� "��������"
	GameNetwork *gameNetwork;	//������� ���� "����"
	MultiClassTunnel *multiClassTunnel;		//������������ ����
};



#endif