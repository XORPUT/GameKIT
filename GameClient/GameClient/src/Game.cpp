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
};

void Game::initGame()
{
	//создание игрового движка HGE
	gameEngine = hgeCreate(HGE_VERSION);

	gameSetting = new GameSetting();
	gameViewer = new GameViewer(gameEngine);
	gameModel = new GameModel();
	gameControl = new GameControl(gameEngine);
	gameNetwork = new GameNetwork();
	multiClassTunnel = new MultiClassTunnel(gameSetting, gameModel, gameViewer, gameControl, gameNetwork);
	
	//инициализация движка
	game->initEngine();

	
};

void Game::destroyGame()
{
	releaseEngine();
};

void Game::initEngine()
{
	gameEngine = hgeCreate(HGE_VERSION);

	//Прикрепление к движку функции обновления каждра
	gameEngine->System_SetState(HGE_FRAMEFUNC, &MyFrameFuncHelper);

	//Ограничение FPS
	gameEngine->System_SetState(HGE_FPS, 50);

	//Установка заголовка окна по-умолчанию
	gameEngine->System_SetState(HGE_TITLE, "Game");
	
	//Устанавливаю полноэкранный режим
	gameEngine->System_SetState(HGE_WINDOWED, true);

	//Устанавливаю режим использования звука библиотеки BASS.dll
	gameEngine->System_SetState(HGE_USESOUND, false);

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

void Game::releaseEngine()
{
	// Clean up and shutdown
	gameEngine->System_Shutdown();
	gameEngine->Release();
};

/*
	Функция которая запускается движком при обновлении кадра
*/
bool Game::FrameFunc()
{
	multiClassTunnel->FrameFunc();
	return false;
};



/*
	Функция запускающая программу
*/
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//Инициализирую игру
	game->initGame();

	return 0;
};
