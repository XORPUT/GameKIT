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

	// Загрузка текстуры
//	HTEXTURE mouseTexture = gameEngine->Texture_Load("mouse.png");

	// Загрузило ли?
//	if(!mouseTexture)
//	{
	////		gameEngine->System_Shutdown();
	//		gameEngine->Release();			
	//}


	
}; 
