#include "GameControl.h"
#include <windows.h>

GameControl::GameControl(HGE* gEngine)
{
	SetGameEngine(gEngine);
};

GameControl::~GameControl()
{

};

bool GameControl::FrameFunc()
{ 
	if (this->gameEngine == 0 )  //���� ��� ������� � ������
	{
		return false;
	}
	else
	{	
		if (gameEngine->Input_GetKeyState(HGEK_W) && gameEngine->Input_GetKeyState(HGEK_A)) {};
		if (gameEngine->Input_GetKeyState(HGEK_W) && gameEngine->Input_GetKeyState(HGEK_D)) {};
		if (gameEngine->Input_GetKeyState(HGEK_S) && gameEngine->Input_GetKeyState(HGEK_A)) {};
		if (gameEngine->Input_GetKeyState(HGEK_S) && gameEngine->Input_GetKeyState(HGEK_D)) {};

		float *coordX = new float; //���������� � ������� ����
		float *coordY = new float; //���������� � ������� ����
		gameEngine->Input_GetMousePos(coordX, coordY);  //��������� ����������� ����
	
		gameModel->setMouseCoord(*coordX, *coordY);

		int countWheelMoves = gameEngine->Input_GetMouseWheel(); //���������� ����� ������������ �������� �������� ����� ������������ ����������� ������ ������� �����. ������������� �������� ��������, ��� �������� ��������� ������, �� ������������; ������������� �������� ��������, ��� �������� ��������� �����, � ������������. ���� ������ �� ���������, �������� ����� 0. 
	}	
	return false; 

};

void GameControl::SetGameEngine(HGE* gEngine)
{
	this->gameEngine = gEngine;
};	

void GameControl::SetModel (GameModel* gModel)
{
	this->gameModel = gModel;
};
