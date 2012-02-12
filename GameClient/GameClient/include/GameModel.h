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

	void paintMouse(float x, float y);	//��������� ���� ���������� ����

protected:

private:
	GameViewer *gameViewer;


	IdGenerator *generatorId;	//��������� Id ��� ��������
	std::vector<GameObject_Player> players;	//������

	GameObject *mouse;	//����� ������
};







#endif