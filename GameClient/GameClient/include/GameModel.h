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
	
	int addPlayer();	//��������� ������, ���������� ��� �������������
	void deletePlayer(GameObject_Player *player);	//������� ������
	bool frameStarted();	//���������� ����� ���������� ����� frame(����)
	bool FrameFunc();	//������� ������� ����������� ������� ��� ���������� �����


	/************************************************************************/
	/* �������������� � "���������"                                         */
	/************************************************************************/
	void setMouseCoord(float mouseX, float mouseY);
protected:

private:
	IdGenerator *generatorId;	//��������� Id ��� ��������
	std::vector<GameObject_Player> players;	//������

	float mouseCoordX, mouseCoordY;
};







#endif