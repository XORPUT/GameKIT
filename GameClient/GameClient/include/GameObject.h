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
	void setCoord(float *coord);	//��������� ������������� �������
	void setTexture(std::string texture);
		
	int getId();	//�������� ������������� �������
	float* getCoord();
	std::string getTexture();

protected:
	int objId;	//���������� ������������� �������
	std::string typeObj;	//��� �������
	float *objCoord; //���������� �������
	float objScale;	//������� �������

	bool visibleObj;	//��������� �������: true - ����� \ false - �����
	std::string textureObj;	//����(����������) � �������� �������

private:
};


#endif