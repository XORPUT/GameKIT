#include "IdGenerator.h"
#include <String>
/*
	Базовый класс "Объект"
*/
class GameObject
{
public:
	GameObject();
	~GameObject();

	void Init(int id);	//Инициализация объекта
	void setId(int id);	//Присвоить идентификатор объекту

protected:
	int objId;	//Уникальный идентификатор объекта
	std::string typeObj;	//Тип объекта
	float objCoordX, objCoordY;	//Координаты объекта
	float objScale;	//Поворот объекта

	bool visibleObj;	//Видимость объекта: true - виден \ false - скрыт
	std::string textureObj;	//Путь(директория) к текстуре объекта

private:
};