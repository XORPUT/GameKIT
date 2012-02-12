#include "GameObject.h"

GameObject::GameObject()
{

};

GameObject::~GameObject()
{

};

void GameObject::Init(int id)
{
	setId(id);
};

void GameObject::setId(int id)
{
	objId = id;
};

void GameObject::setCoord(float *coord)
{
	objCoord[0] = coord[0];
	objCoord[1] = coord[1];
};

void GameObject::setTexture(std::string texture)
{
	textureObj = texture;
};

int GameObject::getId()
{
	return objId;
};

float* GameObject::getCoord()
{
	return objCoord;
};

std::string GameObject::getTexture()
{
	return textureObj;
};