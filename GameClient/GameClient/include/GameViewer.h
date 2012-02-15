#ifndef GAMEVIEWER_H
#define GAMEVIEWER_H

#include "hge.h"
#include "GameObject.h"
#include "hgefont.h"
#include "hgesprite.h"
#include "Point.h"
#include "sprObject.h"
#include "vector"

/*
	����� ����������� �������� �� ������
*/

class GameViewer
{
public:
	GameViewer(HGE *gEngine);
	~GameViewer();

	void SetGameEngine(HGE *gEngine); // �������� ��������� �� ������
	HTEXTURE LoadTexture(std::string textureName);
	void PaintObj(GameObject *obj); // ��������� ������ �������
	void PushDataObj(std::vector<GameObject> *listOfObject); // �������� ������ �������� ��� ���������
	void PaintListObject(); // ��������� ����� ��������
	bool FrameFunc();
protected:

private:
	HGE *gameEngine; // ��������� �� ������� ������
	std::vector<GameObject> *arrayObjects; // ������ ��������
	std::vector<TexturePack> *arrayLoadedTextures;	//������ ����������� �������
};

#endif