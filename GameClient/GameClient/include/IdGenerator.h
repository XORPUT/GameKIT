#ifndef IDGENERATOR_H
#define IDGENERATOR_H



/*
	����� ����������� �������� ��������� � ID ��������
*/
class IdGenerator
{
public:
	IdGenerator();
	~IdGenerator();
	int GenerateId(); //��������� ���������� ��������������
	void FreeId(int delId); // ���������� �������������
protected:
private:
	int counter; //������� �������������� ��������� �����
	int PopFromStackId(); //����� ��������� ������������� �� ����� ��������� ���������������
	void PushToStackId(int freeId);  //�������� �������������� ������������� �� ���� ��������� ���������������
	void DeleteStackId(); //�������� ����� ��������� ���������������
	struct CellStackId  //������ ����� ��������� ���������������
        {
                CellStackId():freeIdStack(0), nextCellStackId(0) //��������� ������
                {}
                CellStackId* nextCellStackId; //��������� �� ��������� ����� ����� ��������� ���������������
                int freeIdStack; //���� ��������������
        };
	CellStackId *HeadStackId; //��������� �� ������ �����
};










#endif