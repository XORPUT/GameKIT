/*
	������� ����. WimMain
*/

#include "Game.h"
#include "hge.h"

//������ ����
Game *game = new Game();

//�������� ���������� ������� ���������� ����� � ������
bool MyFrameFuncHelper() {
	return game->FrameFunc();
};

void Game::initGame()
{
	//�������� �������� ������ HGE
	gameEngine = hgeCreate(HGE_VERSION);

	gameSetting = new GameSetting();
	gameViewer = new GameViewer(gameEngine);
	gameModel = new GameModel();
	gameControl = new GameControl(gameEngine);
	gameNetwork = new GameNetwork();
	multiClassTunnel = new MultiClassTunnel(gameSetting, gameModel, gameViewer, gameControl, gameNetwork);
	
	//������������� ������
	game->initEngine();

	
};

void Game::destroyGame()
{
	releaseEngine();
};

void Game::initEngine()
{
	gameEngine = hgeCreate(HGE_VERSION);

	//������������ � ������ ������� ���������� ������
	gameEngine->System_SetState(HGE_FRAMEFUNC, &MyFrameFuncHelper);

	//����������� FPS
	gameEngine->System_SetState(HGE_FPS, 50);

	//��������� ��������� ���� ��-���������
	gameEngine->System_SetState(HGE_TITLE, "Game");
	
	//������������ ������������� �����
	gameEngine->System_SetState(HGE_WINDOWED, true);

	//������������ ����� ������������� ����� ���������� BASS.dll
	gameEngine->System_SetState(HGE_USESOUND, false);

	if(gameEngine->System_Initiate())
	{
		gameEngine->System_Start();
	}
	else
	{	
		//������ �������������
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
	������� ������� ����������� ������� ��� ���������� �����
*/
bool Game::FrameFunc()
{
	multiClassTunnel->FrameFunc();
	return false;
};



/*
	������� ����������� ���������
*/
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//������������� ����
	game->initGame();

	return 0;
};
