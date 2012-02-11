#include "IdGenerator.h"


IdGenerator::IdGenerator()
{
	counter = 0;
	HeadStackId = 0;  //Создать пустой указатель
};

IdGenerator::~IdGenerator()
{
	DeleteStackId();
};

int IdGenerator::GenerateId()
{
	int returnedId;
	if ((counter == 0) && (HeadStackId == 0))   //Если стек свободных идентефикаторов пуст...
	{
		PushToStackId(++counter);
	}
	if (counter == HeadStackId->freeIdStack)    //Если существует единственный свободный идентефикатор...
	{
		returnedId = PopFromStackId();
		PushToStackId(++counter);
	}
	else                                       //Если в стеке есть освободившиеся идентефикаторы...
	{
		returnedId = PopFromStackId();
		HeadStackId = HeadStackId->nextCellStackId;
	}
	return returnedId;
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
	else   //Если стек не пуст...
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
	if (HeadStackId == 0)    //Если стек пуст... 
	{
		HeadStackId = TempCell;
		TempCell->nextCellStackId = 0;
	}
	else          //Если стек не пуст... 
	{
		TempCell->nextCellStackId=HeadStackId;
		HeadStackId=TempCell;
	}
};

void IdGenerator::DeleteStackId()
{
	while (HeadStackId != 0) //Пока стек не пустой продолжать удаление его элементов
	{
		CellStackId* TempPointer = HeadStackId->nextCellStackId;
		delete HeadStackId;
		HeadStackId = TempPointer;
		delete TempPointer;
	}
	counter = 0;   //после удаления всех элементов обнулить счетчик использованных идентефикаторов
};