#include "MultiClassTunnel.h"


MultiClassTunnel::MultiClassTunnel(GameSetting *gSetting, GameModel *gModel, GameControl *gControl, GameNetwork *gNetwork)
{
	Init(gSetting, gModel, gControl, gNetwork);
};

MultiClassTunnel::~MultiClassTunnel()
{

};

void MultiClassTunnel::Init(GameSetting *gSetting, GameModel *gModel, GameControl *gControl, GameNetwork *gNetwork)
{
	gameSetting = gSetting;
	gameModel = gModel;
	gameControl = gControl;
	gameNetwork = gameNetwork;
	//gameViewer = gViewer;
};

bool MultiClassTunnel::FrameFunc()
{
	gameControl->FrameFunc();
	gameModel->FrameFunc();
//	gameViewer->FrameFunc();

	return false;
};
