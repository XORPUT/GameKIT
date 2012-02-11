#include "IdGenerator.h"


IdGenerator::IdGenerator()
{
	HeadStackId = NULL;
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
	if (HeadStackId == NULL)    //Если стек пуст...   
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
	if (HeadStackId == NULL) 
	{
		HeadStackId = TempCell;
		TempCell->nextCellStackId = NULL;
	}
	else
	{
		TempCell->nextCellStackId=HeadStackId;
		HeadStackId=TempCell;
	}
};

void IdGenerator::DeleteStackId()
{
	while (HeadStackId != NULL)
	{
		CellStackId* TempPointer = HeadStackId->nextCellStackId;
		delete HeadStackId;
		HeadStackId = TempPointer;
		delete TempPointer;
	}
};