#ifndef GAME_H
#define GAME_H

#include <windows.h>
#include "MultiClassTunnel.h"

/*
	����� ������� ����� � ����.
	�������� �� �������� ������������� ������ � ������ �������������� �������.
*/

class Game
{
public:
	void initEngine();	//������������� �������� ������ HGE
	bool FrameFunc();	//������� ������� ����������� ������� ��� ���������� �����
protected:

private:
	HGE *gameEngine;	//������� ������ HGE
};



#endif