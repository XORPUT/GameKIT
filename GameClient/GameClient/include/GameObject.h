#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <String>
#include "Point.h"


/*
	������� ����� "������"
*/
class GameObject
{
public:
	GameObject();
	~GameObject();

	void Init(int id);	//������������� �������

	void setId(int id);	//��������� ������������� �������
	void setType(std::string type);	//��������� ��� �������
	void setCoord(Point coord);	//��������� ������������� �������
	void setTexture(std::string texture);	//���������� �������� �������
		
	int getId();	//�������� ������������� �������
	std::string GameObject::getType(); //�������� ��� �������
	Point getCoord(); //�������� ���������� �������
	std::string getTexture();	//�������� �������� �������

protected:
	int objId;	//���������� ������������� �������
	std::string typeObj;	//��� �������
	Point objCoord; //���������� �������
	float objScale;	//������� �������

	bool visibleObj;	//��������� �������: true - ����� \ false - �����
	std::string textureObj;	//����(����������) � �������� �������

private:
};


#endif