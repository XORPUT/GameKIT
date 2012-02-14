#include "GameModel.h"

GameModel::GameModel()
{
	/* Инициализация генератора случайных чисел */
	srand ( time(NULL) );

	generatorId = new IdGenerator();
	sendListObject = new std::vector<GameObject>();
	mobs = new std::vector<GameObject_Mob>();

	CreatePlayer(Point(150, 150), "admin.png");
};

GameModel::~GameModel()
{
	delete generatorId;
	delete sendListObject;
	delete mobs;
};

int GameModel::CreatePlayer(Point coordPlayer, std::string texturePlayer)
{
	player.setId( generatorId->GenerateId() );
	player.setCoord(coordPlayer);
	player.setTexture(texturePlayer);

	return player.getId();
};

int GameModel::addMob(Point coordMob, std::string textureMob)
{
	GameObject_Mob *newMob = new GameObject_Mob();
	newMob->setId( generatorId->GenerateId() );
	newMob->setCoord(coordMob);
	newMob->setTexture(textureMob);
	mobs->push_back(*newMob);

	return newMob->getId();
};

void GameModel::deleteMob(GameObject_Mob *mob)
{
	generatorId->FreeId( mob->getId() );
	delete mob;
};

void GameModel::GenerateSendListObjects()
{
	sendListObject->clear();

	//Добавляю игрока
	sendListObject->push_back(player);

	//Добавляю всех мобов
	std::vector<GameObject_Mob>::iterator it;
	for (it = mobs->begin(); it != mobs->end(); it++)
	{
		sendListObject->push_back( *it );
	}	
	
};

bool GameModel::FrameFunc()
{
	if (std::rand() % 200 + 1 == 20)
	{
		addMob(Point((float)(std::rand() % 200 + 1) ,(float)(std::rand() % 200 + 1)), "zombie.png");
	}

	std::vector<GameObject_Mob>::iterator it;
	for (it = mobs->begin(); it != mobs->end(); it++)
	{
		it->setCoord( Point( 
			it->getCoord().x - ((it->getCoord().x - player.getCoord().x) / 200), 
			it->getCoord().y - ((it->getCoord().y - player.getCoord().y) / 200)  
			) );
	}	

	player.setCoord(mouse.getCoord());

	injectSendListObjectToViewer();
	GenerateSendListObjects();
	return false;
};


void GameModel::setMouseCoord(float mouseX, float mouseY)
{
	Point coord;	//Координаты мыши
	coord.x = mouseX;
	coord.y = mouseY;
	mouse.setCoord(coord);
};

void GameModel::SetViewer(GameViewer* gViewer)
{
	this->gameViewer = gViewer;
};

void GameModel::injectSendListObjectToViewer()
{
	gameViewer->PushDataObj(sendListObject);
};