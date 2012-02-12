#include "MultiClassTunnel.h"


MultiClassTunnel::MultiClassTunnel()
{

};

MultiClassTunnel::~MultiClassTunnel()
{

};

void MultiClassTunnel::Init(GameSetting gSetting, GameModel gModel, GameControl gControl, GameNetwork gNetwork)
{

};

bool MultiClassTunnel::FrameFunc()
{
	gameControl->FrameFunc();
	gameModel->FrameFunc();
//	gameViewer->FrameFunc();

	return false;
};
