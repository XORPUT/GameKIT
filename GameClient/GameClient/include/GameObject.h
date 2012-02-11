#include "IdGenerator.h"
#include <windows.h>
/*
	Базовый класс "Объект"
*/
class GameObject
{
public:
	GameObject();
	~GameObject();
protected:
	int id;	//Уникальный идентификатор объекта
private:
};