//Автор - Перунов ВАдим
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include "Building.h"

using namespace std;
int main() {
	setlocale(0, "RUS");
	
	Storage st1(500, 1250);
	Manifacture mn1(500, 1, Specialization::Sawmill), mn2(500, 2, Specialization::Quarry), mn3(500, 3, Specialization::Goldmine), mn4(500, 4, Specialization::Ironmine), mn5(500, 5, Specialization::Farm);
	Defense def(500, 7);
	//статические массивы обьектов производных классов
	Storage stor[5];
	Manifacture prod[5];

	stor[0] = Storage(600, 1000);
	stor[1] = Storage(600, 1500);
	stor[2] = Storage(600, 900);
	stor[3] = Storage(600, 800);
	stor[4] = Storage(600, 2000);

	prod[0] = Manifacture(600, 5, Specialization::Sawmill);
	prod[1] = Manifacture(600, 4, Specialization::Quarry);
	prod[2] = Manifacture(600, 3, Specialization::Ironmine);
	prod[3] = Manifacture(600, 4, Specialization::Goldmine);
	prod[4] = Manifacture(600, 10, Specialization::Farm);

	while (!(GetAsyncKeyState('F'))) {
		system("cls");

		mn5.Produce(st1);
		mn1.Produce(st1);
		mn2.Produce(st1);
		mn3.Produce(st1);
		mn4.Produce(st1);


		if (GetAsyncKeyState('1')) mn1.Upgrade();
		if (GetAsyncKeyState('2')) mn2.Upgrade();
		if (GetAsyncKeyState('3')) mn3.Upgrade();
		if (GetAsyncKeyState('4')) mn4.Upgrade();
		if (GetAsyncKeyState('5')) mn5.Upgrade();
		if (GetAsyncKeyState('6')) st1.Upgrade(400);
		if (GetAsyncKeyState('7')) def.Upgrade(3);

		cout << "Заполненность хранилища: " << st1.CurrentRes() << '/' << st1.GetCapacity() << endl;
		cout << "Дерево: " << st1.Wood  << endl;
		cout << "Камень: " << st1.Stone << endl;
		cout << "Золото: " << st1.Gold  << endl;
		cout << "Железо: " << st1.Iron  << endl;
		cout << "Еда: "	   << st1.Food  << endl;

		cout << "\n\n";
		def.Attack();

		for (unsigned i = 0; i < 5;i++) {
			prod[i].Produce(stor[i]);
			cout << stor[i].ToString() << "\n";
		}
		Sleep(1000);
	}

	cout << prod[0].ToString()<<'\n';

	Defense d(500, 5);
	Building *b1  = &d;
	cout << b1->ToString();
}