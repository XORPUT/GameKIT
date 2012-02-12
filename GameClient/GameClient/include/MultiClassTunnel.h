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
	bool FrameFunc();	//������� ������� ����������� ������� ��� ���������� �����
protected:

private:
	GameSetting *gameSetting;
	GameModel *gameModel;
	GameControl *gameControl;
	GameNetwork *gameNetwork;
	
	/*	������������� ����� ����� ������� ������
	GameViewer *gameViewer;
	*/
};






#endif