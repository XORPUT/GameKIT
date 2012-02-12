#include "GameControl.h"

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
		switch (gameEngine->Input_GetKey()) //��������� ������� ������ � ������ ����
		{
			case HGEK_W: {break;}
			case HGEK_A: {break;}
			case HGEK_S: {break;}
			case HGEK_D: {break;}
			case HGEK_ESCAPE: 
			{
	//			MessageBox(0, '������� ���� ����������!!!', 'O_o', MB_OK);
				break;
			}
			case HGEK_F: {break;}
			case HGEK_G: {break;}
			case HGEK_Z: {break;}
			case HGEK_X: {break;}
			case HGEK_C: {break;}
			case HGEK_LBUTTON: {break;}
			case HGEK_RBUTTON: {break;}
			case HGEK_MBUTTON: {break;}
			break;
		};
		float *dX = new float; //���������� � ������� ����
		float *dY = new float; //���������� � ������� ����
		gameEngine->Input_GetMousePos(dX, dY);  //��������� ����������� ����
	

		int countWheelMoves = gameEngine->Input_GetMouseWheel(); //���������� ����� ������������ �������� �������� ����� ������������ ����������� ������ ������� �����. ������������� �������� ��������, ��� �������� ��������� ������, �� ������������; ������������� �������� ��������, ��� �������� ��������� �����, � ������������. ���� ������ �� ���������, �������� ����� 0. 
	}	
	return false; 

};

void GameControl::SetGameEngine(HGE* gEngine)
{
	this->gameEngine = gEngine;
};	
	
