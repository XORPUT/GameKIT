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
	switch (gameEngine->Input_GetKey()) //��������� ������� ������ � ������ ����
	{
	case HGEK_W: {}
	case HGEK_A: {}
	case HGEK_S: {}
	case HGEK_D: {}
	case HGEK_ESCAPE: 
		{
//			MessageBox(0, '������� ���� ����������!!!', 'O_o', MB_OK);
		}
	case HGEK_F: {}
	case HGEK_G: {}
	case HGEK_Z: {}
	case HGEK_X: {}
	case HGEK_C: {}
	case HGEK_LBUTTON: {}
	case HGEK_RBUTTON: {}
	case HGEK_MBUTTON: {}
					   break;
	};

/*	float *dX; //��������� �� float, ���� ���������� ��������� X-���������� �������.
	float *dY; //��������� �� float, ���� ���������� ��������� Y-���������� �������.
	switch (gameEngine->Input_GetMousePos(dX, dY))  //��������� ����������� ����
	{
		case (dX>0 && dY>0) {return dX*dY-dX};
			case 
				case 
				case 
				break;
	};

	int countWheelMoves = gameEngine->Input_GetMouseWheel(); //���������� ����� ������������ �������� �������� ����� ������������ ����������� ������ ������� �����. ������������� �������� ��������, ��� �������� ��������� ������, �� ������������; ������������� �������� ��������, ��� �������� ��������� �����, � ������������. ���� ������ �� ���������, �������� ����� 0. 
	switch (countWheelMoves) //��������� ������������� ����
	{
	case countWheelMoves>0: {return countWheelMoves;}
	case countWheelMoves<0: {return countWheelMoves;}
							break;
	};
*/
	return false;
};

void GameControl::SetGameEngine(HGE* gEngine)
{
	gameEngine = gEngine;
};	
	
