#include "IdGenerator.h"


IdGenerator::IdGenerator()
{
	counter = 0;
	HeadStackId = 0;  //������� ������ ���������
};

IdGenerator::~IdGenerator()
{
	DeleteStackId();
};

int IdGenerator::GenerateId()
{
	int returnedId;
	if (HeadStackId == 0)  //���� ���� ��������� ��������������� ����...
	{
		PushToStackId(counter);
	}
	if (counter == HeadStackId->freeIdStack)    //���� ���������� ������������ ��������� �������������...
    {
		returnedId = PopFromStackId();
	}
	else     //���� � ����� ���� �������������� ��������������...
	{
		returnedId = PopFromStackId();
	}
	return returnedId;
};

void IdGenerator::FreeId(int delId)
{
	PushToStackId(delId);
};

int IdGenerator::PopFromStackId() //����� ������ ��������� �������������
{
	int firstFreeId;
	if (HeadStackId == 0)    //���� ���� ����...   
	{
		return -1;
	}   
	else   //���� ���� �� ����...
	{
		CellStackId* deleteTopCellStackId = HeadStackId;
		if (HeadStackId->nextCellStackId == 0)	//���� ������������ ������� � �����
		{
			HeadStackId->nextCellStackId = new CellStackId;
			HeadStackId->nextCellStackId->freeIdStack = ++counter;
			HeadStackId->nextCellStackId->nextCellStackId = 0;
		}
		firstFreeId = HeadStackId->freeIdStack;
		HeadStackId = HeadStackId->nextCellStackId;
		delete deleteTopCellStackId;
	}
	return firstFreeId;
};

void IdGenerator::PushToStackId(int freeId) //�������� �������������� ������������� �� ���� ��������� ���������������
{
	CellStackId* TempCell;
	TempCell = new CellStackId;
	TempCell->freeIdStack = freeId;
	if (HeadStackId == 0)    //���� ���� ����... 
	{
		HeadStackId = TempCell;
		TempCell->nextCellStackId = 0;
	}
	else          //���� ���� �� ����... 
	{
		TempCell->nextCellStackId=HeadStackId;
		HeadStackId=TempCell;
	}
};

void IdGenerator::DeleteStackId()
{
	while (HeadStackId != 0) //���� ���� �� ������ ���������� �������� ��� ���������
	{
		CellStackId* TempPointer = HeadStackId->nextCellStackId;
		delete HeadStackId;
		HeadStackId = TempPointer;
		delete TempPointer;
	}
	counter = 0;   //����� �������� ���� ��������� �������� ������� �������������� ���������������
};