#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <String>
#include "Point.h"


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
	void setType(std::string type);	//Присвоить тип объекту
	void setCoord(Point coord);	//Присвоить идентификатор объекту
	void setTexture(std::string texture);	//Установить текстуру объекту
		
	int getId();	//Получить идентификатор объекта
	std::string GameObject::getType(); //Получить тип объекта
	Point getCoord(); //Получить координаты объекта
	std::string getTexture();	//Получить текстуру объекта

protected:
	int objId;	//Уникальный идентификатор объекта
	std::string typeObj;	//Тип объекта
	Point objCoord; //Координаты объекта
	float objScale;	//Поворот объекта

	bool visibleObj;	//Видимость объекта: true - виден \ false - скрыт
	std::string textureObj;	//Путь(директория) к текстуре объекта

private:
};


#endif