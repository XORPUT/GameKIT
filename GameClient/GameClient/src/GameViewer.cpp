#include "GameViewer.h"

GameViewer::GameViewer(HGE *gEngine)
{	
	SetGameEngine(gEngine);
};

void GameViewer::SetGameEngine(HGE *gEngine)
{
	gameEngine = gEngine;
};

void GameViewer::PaintOneObj(GameObject *objId)
{
	
};

void GameViewer::PaintObjMouse(GameObject *objId)
{
	int a = 1;

	// �������� ��������
/*	HTEXTURE mouseTexture = gameEngine->Texture_Load("mouse.png");

	// ��������� ��?
	if(!mouseTexture)
	{
			gameEngine->System_Shutdown();
			gameEngine->Release();			
	}
	
//	hgeSprite *sprMouseTexture;
//	sprMouseTexture = new hgeSprite(mouseTexture,0,0,64,64);
	
*/

}; 
