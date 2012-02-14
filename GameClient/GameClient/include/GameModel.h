#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "GameViewer.h"
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
	
	bool FrameFunc();	//������� ������� ����������� ������� ��� ���������� �����
	void injectSendListObjectToViewer();	//������� ��������� �� ������ �������� ��� ��������� �������
	
	int CreatePlayer(Point coordPlayer, std::string texturePlayer);	//������ ������, ���������� ��� �������������
	int addMob(Point coordMob, std::string textureMob);	//��������� ����, ���������� ��� �������������
	void deletePlayer(GameObject_Player *player);	//������� ������
	void deleteMob(GameObject_Mob *mob);	//������� ����
	void GenerateSendListObjects();


	/************************************************************************/
	/* �������������� � "���������"                                         */
	void setMouseCoord(float mouseX, float mouseY);	//���������� ������� ���������� ����
	/************************************************************************/

	/************************************************************************/
	/* �������������� � "�����"                                             */
	void SetViewer(GameViewer* gViewer);	//���������� Viewer
	void paintSendListObject(std::vector<GameObject> *sendList);	//�������� �� ��������� ������� ��������
	/************************************************************************/

protected:

private:
	GameViewer *gameViewer;

	IdGenerator *generatorId;	//��������� Id ��� ��������
	std::vector<GameObject_Mob> *mobs;	//������ �����
	std::vector<GameObject> *sendListObject;	//������ �������� ��� ��������

	GameObject_Player player;	//�����
	GameObject mouse;	//����� ������
};







#endif