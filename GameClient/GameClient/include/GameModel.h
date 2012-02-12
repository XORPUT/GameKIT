#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>

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
	
	
	
	int addPlayer();	//��������� ������, ���������� ��� �������������
	void deletePlayer(GameObject_Player *player);	//������� ������
	bool FrameFunc();	//������� ������� ����������� ������� ��� ���������� �����


	/************************************************************************/
	/* �������������� � "���������"                                         */
	void setMouseCoord(float mouseX, float mouseY);	//���������� ������� ���������� ����
	/************************************************************************/

	/************************************************************************/
	/* �������������� � "�����"                                             */
	void SetViewer(GameViewer* gViewer);	//���������� Viewer
	/************************************************************************/

	void paintSendListObject(std::vector<GameObject> sendList);	//�������� �� ��������� ������� ��������

protected:

private:
	GameViewer *gameViewer;


	IdGenerator *generatorId;	//��������� Id ��� ��������
	std::vector<GameObject_Player> players;	//������

	std::vector<GameObject> *sendListObject;	//������ �������� ��� ��������
	GameObject *mouse;	//����� ������
};







#endif