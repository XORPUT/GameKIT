#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include "hge.h"

/*
	Класс отвечающий за управление пользователем игрой (клавиатура, мышь, интерфейсные события)
*/
class GameControl
{
public:
	GameControl();
	~GameControl();
	bool FrameFunc();	//Функция которая запускается движком при обновлении кадра
protected:

private:

};

#endif