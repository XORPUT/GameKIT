#include "GameViewer.h"

GameViewer::GameViewer(HGE *gEngine)
{	
	SetGameEngine(gEngine);
	arrayLoadedTextures = new std::vector<TexturePack>();
};

GameViewer::~GameViewer()
{	
	delete arrayLoadedTextures;
};

HTEXTURE GameViewer::LoadTexture(std::string textureName)
{
	
	std::vector<TexturePack>::iterator it;
	for (it = arrayLoadedTextures->begin(); it != arrayLoadedTextures->end(); it++)
	{
		//Если текстура уже загружалась
		if (it->nameTexture == textureName)
		{
			return it->texture;
		}
	}
	
	// Загрузка текстуры
	HTEXTURE textureObject = gameEngine->Texture_Load(textureName.c_str());

	arrayLoadedTextures->push_back( TexturePack(textureName, textureObject) );
	return textureObject;
};

void GameViewer::SetGameEngine(HGE *gEngine)
{
	gameEngine = gEngine;
};

void GameViewer::PaintObj(GameObject *obj)
{
	HTEXTURE textureObject = LoadTexture(obj->getTexture());
	// Загрузка текстуры
	if(!textureObject)
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
	spr = new hgeSprite(textureObject,0,0,(float)gameEngine->Texture_GetWidth(textureObject, true),(float)gameEngine->Texture_GetHeight(textureObject, true));

	spr->RenderEx(pObjects.x, pObjects.y, pObjects.rot, pObjects.scale);
	
	delete spr;
	//gameEngine->Texture_Free(textureObject);
}; 

void GameViewer::PushDataObj(std::vector<GameObject> *listOfObject)
{
	arrayObjects = listOfObject;
};

void GameViewer::PaintListObject()
{
	gameEngine->Gfx_BeginScene();
	gameEngine->Gfx_Clear(0);
	hgeFont *fnt = new hgeFont("font1.fnt");
	fnt->printf(5, 5, HGETEXT_LEFT, "Zombies:%.3d\nFPS:%d", arrayObjects->size(), gameEngine->Timer_GetFPS());

	std::vector<GameObject>::iterator it;
	for (it = arrayObjects->begin(); it != arrayObjects->end(); it++)
	{
		PaintObj( &*it ); //Бред, но ток так и работает...
	}

	gameEngine->Gfx_EndScene();
};

bool GameViewer::FrameFunc()
{
	PaintListObject();
	return false;
};