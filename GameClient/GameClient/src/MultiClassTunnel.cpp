#include "MultiClassTunnel.h"


MultiClassTunnel::MultiClassTunnel(GameSetting *gSetting, GameModel *gModel, GameViewer *gViewer, GameControl *gControl, GameNetwork *gNetwork)
{
	Init(gSetting, gModel, gViewer, gControl, gNetwork);
};

MultiClassTunnel::~MultiClassTunnel()
{

};

void MultiClassTunnel::Init(GameSetting *gSetting, GameModel *gModel, GameViewer *gViewer, GameControl *gControl, GameNetwork *gNetwork)
{
	gameSetting = gSetting;


	gameViewer = gViewer;
	
	gameModel = gModel;
	gameModel->SetViewer(gViewer);
	
	gameControl = gControl;
	gameControl->SetModel(gModel);

	gameNetwork = gameNetwork;
};

bool MultiClassTunnel::FrameFunc()
{
	gameControl->FrameFunc();
	gameModel->FrameFunc();
//	gameViewer->FrameFunc();

	return false;
};
