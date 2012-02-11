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