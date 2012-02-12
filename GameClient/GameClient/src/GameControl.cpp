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
	switch (gameEngine->Input_GetKey()) //обработка нажатий клавиш и кнопок мыши
	{
	case HGEK_W: {}
	case HGEK_A: {}
	case HGEK_S: {}
	case HGEK_D: {}
	case HGEK_ESCAPE: 
		{
//			MessageBox(0, '«акрыть игру невозможно!!!', 'O_o', MB_OK);
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

/*	float *dX; //”казатель на float, куда необходимо сохранить X-координату курсора.
	float *dY; //”казатель на float, куда необходимо сохранить Y-координату курсора.
	switch (gameEngine->Input_GetMousePos(dX, dY))  //обработка перемещени€ мыши
	{
		case (dX>0 && dY>0) {return dX*dY-dX};
			case 
				case 
				case 
				break;
	};

	int countWheelMoves = gameEngine->Input_GetMouseWheel(); //¬озвращает число прокрученных зубчиков колесика мышки относительно предыдущего вызова функции кадра. ѕоложительное значение означает, что колесико крутилось вперед, от пользовател€; отрицательное значение означает, что колесико кротилось назад, к пользователю. ≈сли колесо не вращалось, значение равно 0. 
	switch (countWheelMoves) //обработка прокручивани€ мыши
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
	
