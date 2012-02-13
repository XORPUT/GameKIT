#include "GameViewer.h"

GameViewer::GameViewer(HGE *gEngine)
{	
	SetGameEngine(gEngine);
};

void GameViewer::SetGameEngine(HGE *gEngine)
{
	gameEngine = gEngine;
};

void GameViewer::PaintObj(GameObject *obj)
{
	 
	// Загрузка текстуры
	HTEXTURE mouseTexture = gameEngine->Texture_Load(obj->getTexture().c_str());

	// Загрузило ли?
	if(!mouseTexture)
	{
			gameEngine->System_Shutdown();
			gameEngine->Release();
	}
	
	sprObject pObjects;

	pObjects.x = obj->getCoord().x;
	pObjects.y = obj->getCoord().y;
	pObjects.scale = 1;
	pObjects.rot = 0;

	hgeSprite *spr;
	spr = new hgeSprite(mouseTexture,0,0,32,32);

	gameEngine->Gfx_Clear(0);

	gameEngine->Gfx_BeginScene();

	//spr->RenderEx(pObjects.x, pObjects.y, pObjects.rot, pObjects.scale);

	gameEngine->Gfx_EndScene();

}; 

void GameViewer::PushDataObj(std::vector<GameObject> *listOfObject)
{
	arrayObjects = listOfObject;
};

void GameViewer::PaintListObject()
{
	for (int i=0; i<=arrayObjects->size(); i++)
	{
		PaintObj(arrayObjects[i]);
	}
};

bool GameViewer::FrameFunc()
{
	return false;
};