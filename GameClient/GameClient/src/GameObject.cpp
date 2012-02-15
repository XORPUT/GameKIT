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

void GameObject::setType(std::string type)
{
	this->typeObj = type;
};

void GameObject::setCoord(Point coord)
{
	objCoord = coord;
};

void GameObject::setTexture(std::string texture)
{
	textureObj = texture;
};

int GameObject::getId()
{
	return objId;
};

std::string GameObject::getType()
{
	return this->typeObj;
};

Point GameObject::getCoord()
{
	return objCoord;
};

std::string GameObject::getTexture()
{
	return textureObj;
};