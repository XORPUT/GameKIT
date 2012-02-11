/*
	 ласс описывающий операции св€занные с ID объектов
*/
class IdGenerator
{
public:
	IdGenerator();
	~IdGenerator();
	int GenerateId(); //√енераци€ свободного идентефикатора
	void FreeId(int delId); // ќсвободить идентефикатор
protected:
private:
	int PopFromStackId(); //¬з€ть свободный идентефикатор со стека свободных идентефикаторов
	void PushToStackId(int freeId);  //ѕоложить освободившийс€ идентефикатор на стек свободных идентефикаторов
	void DeleteStackId(); //”даление стека свободных идентефикаторов
	struct CellStackId  //€чейка стека свободных идентефикаторов
        {
                CellStackId():freeIdStack(0), nextCellStackId(0) //структура €чейки
                {}
                CellStackId* nextCellStackId; //указатель на следующую €чеку стека свободных идентефикаторов
                int freeIdStack; //поле идентефикатора
        };
	CellStackId *HeadStackId; //указатель на начало стека
};