#include "IdGenerator.h"
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

protected:
	int objId;	//���������� ������������� �������
	std::string typeObj;	//��� �������
	float objCoordX, objCoordY;	//���������� �������
	float objScale;	//������� �������

	bool visibleObj;	//��������� �������: true - ����� \ false - �����
	std::string textureObj;	//����(����������) � �������� �������

private:
};