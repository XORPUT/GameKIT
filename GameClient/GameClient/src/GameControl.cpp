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
	if (this->gameEngine == 0 )  //Если нет доступа к движку
	{
		return false;
	}
	else
	{	
		if (gameEngine->Input_GetKeyState(HGEK_W) && gameEngine->Input_GetKeyState(HGEK_A)) {};
		if (gameEngine->Input_GetKeyState(HGEK_W) && gameEngine->Input_GetKeyState(HGEK_D)) {};
		if (gameEngine->Input_GetKeyState(HGEK_S) && gameEngine->Input_GetKeyState(HGEK_A)) {};
		if (gameEngine->Input_GetKeyState(HGEK_S) && gameEngine->Input_GetKeyState(HGEK_D)) {};

		float *coordX = new float; //Координата Х курсора мыши
		float *coordY = new float; //Координата У курсора мыши
		gameEngine->Input_GetMousePos(coordX, coordY);  //обработка перемещения мыши
	
		gameModel->setMouseCoord(*coordX, *coordY);

		int countWheelMoves = gameEngine->Input_GetMouseWheel(); //Возвращает число прокрученных зубчиков колесика мышки относительно предыдущего вызова функции кадра. Положительное значение означает, что колесико крутилось вперед, от пользователя; отрицательное значение означает, что колесико кротилось назад, к пользователю. Если колесо не вращалось, значение равно 0. 
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
