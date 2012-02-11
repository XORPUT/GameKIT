#include "IdGenerator.h"


IdGenerator::IdGenerator()
{
	HeadStackId = 0;
};

IdGenerator::~IdGenerator()
{
	DeleteStackId();
};

int IdGenerator::GenerateId()
{
	return PopFromStackId(); 
};

void IdGenerator::FreeId(int delId)
{
	PushToStackId(delId);
};

int IdGenerator::PopFromStackId() //Взять первый свободный идентефикатор
{
	int firstFreeId;
	if (HeadStackId == 0)    //Если стек пуст...   
	{
		return -1;
	}   
	else   //Если стек не пуст
	{
		CellStackId* deleteTopCellStackId = HeadStackId;
		HeadStackId = HeadStackId->nextCellStackId;
		firstFreeId = HeadStackId->freeIdStack;
		delete deleteTopCellStackId;
	}
	return firstFreeId;
};

void IdGenerator::PushToStackId(int freeId) //Положить освободившийся идентефикатор на стек свободных идентефикаторов
{
	CellStackId* TempCell;
	TempCell = new CellStackId;
	TempCell->freeIdStack = freeId;
	if (HeadStackId == 0) 
	{
		HeadStackId = TempCell;
		TempCell->nextCellStackId = 0;
	}
	else
	{
		TempCell->nextCellStackId=HeadStackId;
		HeadStackId=TempCell;
	}
};

void IdGenerator::DeleteStackId()
{
	while (HeadStackId != 0)
	{
		CellStackId* TempPointer = HeadStackId->nextCellStackId;
		delete HeadStackId;
		HeadStackId = TempPointer;
		delete TempPointer;
	}
};