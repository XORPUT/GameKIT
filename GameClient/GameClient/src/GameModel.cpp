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

int GameModel::addMob(std::string typeMob, Point coordMob, std::string textureMob)
{
	GameObject_Mob *newMob = new GameObject_Mob();
	newMob->setId( generatorId->GenerateId() );
	newMob->setType( typeMob );
	newMob->setCoord(coordMob);
	newMob->setTexture(textureMob);
	mobs->push_back(*newMob);

	return newMob->getId();
};

void GameModel::deleteMob(GameObject_Mob *mob)
{
	generatorId->FreeId( mob->getId() );
	//Ищу нужного моба мобов
	std::vector<GameObject_Mob>::iterator it;
	for (it = mobs->begin(); it != mobs->end(); it++)
	{
		if (it->getId() == mob->getId())
		{
			mobs->erase(it);
			break;
		}
	}	

	//delete mob;
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
	if (std::rand() % 10 + 1 == 1)
	{
		if (mobs->size()>200)
		{
			deleteMob(&mobs->at(0));
			deleteMob(&mobs->at(0));
		}
		addMob("mob_zombie" ,Point((float)(std::rand() % 1000 - 200) ,(float)(std::rand() % 2 - 100)), "zombie.png");
		addMob("mob_zombie", Point((float)(std::rand() % 1000 - 200) ,(float)(std::rand() % 2 + 600)), "zombie.png");
	}

	std::vector<GameObject_Mob>::iterator it;
	for (it = mobs->begin(); it != mobs->end(); it++)
	{
		if ( ( abs(it->getCoord().x - player.getCoord().x) < 60 ) && ( abs(it->getCoord().y - player.getCoord().y) < 60 ) )
		{
			it->setType("mob_zombie_noob");
		}

		if (it->getType() == "mob_zombie")
		{
			it->setCoord(Point( it->getCoord().x - ((it->getCoord().x - player.getCoord().x) / (std::rand() % 400 + 200)), 
								it->getCoord().y - ((it->getCoord().y - player.getCoord().y) / (std::rand() % 400 + 200)))
						);
		} else
		if (it->getType() == "mob_zombie_noob")
		{
			it->setTexture("zombie_noob.png");
			it->setCoord(Point( it->getCoord().x + (500 / sqrt( 1.0 * abs(it->getCoord().x - player.getCoord().x) * abs(it->getCoord().x - player.getCoord().x) + abs(it->getCoord().y - player.getCoord().y) * abs(it->getCoord().y - player.getCoord().y) ) ) * ((abs(it->getCoord().x - player.getCoord().x) / (it->getCoord().x - player.getCoord().x)) ), 
								it->getCoord().y + (500 / sqrt( 1.0 * abs(it->getCoord().x - player.getCoord().x) * abs(it->getCoord().x - player.getCoord().x) + abs(it->getCoord().y - player.getCoord().y) * abs(it->getCoord().y - player.getCoord().y) ) ) * ((abs(it->getCoord().y - player.getCoord().y) / (it->getCoord().y - player.getCoord().y)) ))
						);
		}
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