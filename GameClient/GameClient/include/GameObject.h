#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <String>
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
	int getId();	//�������� ������������� �������

protected:
	int objId;	//���������� ������������� �������
	std::string typeObj;	//��� �������
	float objCoordX, objCoordY;	//���������� �������
	float objScale;	//������� �������

	bool visibleObj;	//��������� �������: true - ����� \ false - �����
	std::string textureObj;	//����(����������) � �������� �������

private:
};


#endif