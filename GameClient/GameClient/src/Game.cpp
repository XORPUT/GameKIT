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
	game->initEngine();

	gameSetting = new GameSetting();
	gameModel = new GameModel();
	gameControl = new GameControl();
	//�������������� ����� �������� ����� //        gameViewer = new GameViewer();
	gameNetwork = new GameNetwork();
	multiClassTunnel = new MultiClassTunnel();
};

void Game::initEngine()
{
	gameEngine = hgeCreate(HGE_VERSION);

	//������������ � ������ ������� ���������� ������
	gameEngine->System_SetState(HGE_FRAMEFUNC, &MyFrameFuncHelper);

	//��������� ��������� ���� ��-���������
	gameEngine->System_SetState(HGE_TITLE, "Game");
	
	//������������ ������������� �����
	gameEngine->System_SetState(HGE_WINDOWED, true);

	//������������ ����� ������������� ����� ���������� BASS.dll
	gameEngine->System_SetState(HGE_USESOUND, true);

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

/*
	������� ������� ����������� ������� ��� ���������� �����
*/
bool Game::FrameFunc()
{
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
