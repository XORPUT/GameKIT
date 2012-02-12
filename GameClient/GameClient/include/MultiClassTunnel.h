#ifndef MULTICLASSTUNNEL_H
#define MULTICLASSTUNNEL_H

#include "GameModel.h"
#include "GameViewer.h"
#include "GameControl.h"
#include "GameNetwork.h"
#include "GameSetting.h"


/*
	�����, ���������� �� ������������ ��������������
*/

class MultiClassTunnel
{
public:
	MultiClassTunnel();
	~MultiClassTunnel();
	void Init(GameSetting gSetting, GameModel gModel, GameControl gControl, GameNetwork gNetwork);
	bool FrameFunc();	//������� ������� ����������� ������� ��� ���������� �����
protected:

private:
	GameSetting *gameSetting;	//������� ���� "������������ ����"
	GameModel *gameModel;		//������� ���� "������"
	/*	������������� ����� ����� ������� ������
	GameViewer *gameViewer;
	*/
	GameControl *gameControl;	//������� ���� "��������"
	GameNetwork *gameNetwork;	//������� ���� "����"
};






#endif