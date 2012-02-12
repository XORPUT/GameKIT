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
	if (this->gameEngine == 0 )  //Если нет доступа к движку
	{
		return false;
	}
	else
	{	
		switch (gameEngine->Input_GetKey()) //обработка нажатий клавиш и кнопок мыши
		{
			case HGEK_W: {break;}
			case HGEK_A: {break;}
			case HGEK_S: {break;}
			case HGEK_D: {break;}
			case HGEK_ESCAPE: 
			{
	//			MessageBox(0, 'Закрыть игру невозможно!!!', 'O_o', MB_OK);
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
		float *dX = new float; //Координата Х курсора мыши
		float *dY = new float; //Координата У курсора мыши
		gameEngine->Input_GetMousePos(dX, dY);  //обработка перемещения мыши
	

		int countWheelMoves = gameEngine->Input_GetMouseWheel(); //Возвращает число прокрученных зубчиков колесика мышки относительно предыдущего вызова функции кадра. Положительное значение означает, что колесико крутилось вперед, от пользователя; отрицательное значение означает, что колесико кротилось назад, к пользователю. Если колесо не вращалось, значение равно 0. 
	}	
	return false; 

};

void GameControl::SetGameEngine(HGE* gEngine)
{
	this->gameEngine = gEngine;
};	
	
