#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>

#include "GameObject.h"
#include "GameGetDataObj.h"

#include "IdGenerator.h"

#include "GameObject_Player.h"

/*
	������� ����� ��������������� ����� ������
*/
class GameModel
{
public:
	GameModel();
	~GameModel();
	int AddPlayer();	//��������� ������, ���������� ��� �������������
protected:

private:
	IdGenerator *generatorId;
	std::vector<GameObject_Player> players;

};







#endif