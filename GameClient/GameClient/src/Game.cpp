/*
	Базовый файл. WimMain
*/

#include "Game.h"
#include "hge.h"

//Создаю игру
Game *game = new Game();

//Помогает прикрепить функцию обновления кадра к классу
bool MyFrameFuncHelper() {
	return game->FrameFunc();
}

void Game::initEngine()
{
	gameEngine = hgeCreate(HGE_VERSION);

	//Прикрепление к движку функции обновления каждра
	gameEngine->System_SetState(HGE_FRAMEFUNC, &MyFrameFuncHelper);

	//Установка заголовка окна по-умолчанию
	gameEngine->System_SetState(HGE_TITLE, "Game");
	
	//Устанавливаю полноэкранный режим
	gameEngine->System_SetState(HGE_WINDOWED, true);

	//Устанавливаю режим использования звука библиотеки BASS.dll
	gameEngine->System_SetState(HGE_USESOUND, true);

	if(gameEngine->System_Initiate())
	{
		gameEngine->System_Start();
	}
	else
	{	
		//Ошибка инициализации
		MessageBox(0, gameEngine->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}


};

/*
	Функция которая запускается движком при обновлении кадра
*/
bool Game::FrameFunc()
{
	return false;
};


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//Инициализирую игру
	game->initEngine();

	return 0;
};
