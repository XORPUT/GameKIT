#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

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
	int getId();	//Получить идентификатор объекта

protected:
	int objId;	//Уникальный идентификатор объекта
	std::string typeObj;	//Тип объекта
	float objCoordX, objCoordY;	//Координаты объекта
	float objScale;	//Поворот объекта

	bool visibleObj;	//Видимость объекта: true - виден \ false - скрыт
	std::string textureObj;	//Путь(директория) к текстуре объекта

private:
};


#endif