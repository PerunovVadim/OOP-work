//автор - Перунов Вадим ИВТ-22
#include <iostream>
#include "ComplexNumber.h"

using namespace std;


int main(){
	ComplexNumber a(5,9),b(4,3),c;

	cout <<"Value of a:" + (a).ToString() <<endl;

	cout <<"Value of b:" + (b).ToString() <<endl;;

	cout <<"Value of c:" + (c).ToString() <<endl;;

	c = b;
	cout <<"c = b:\n" << c.ToString();

	cout <<"a + b equal:" + (a+b).ToString() <<endl;

	cout <<"a - b equal:" + (a-b).ToString() <<endl;

	cout <<"a * b equal:" + (a*b).ToString() <<endl;

	cout <<"a * 5 equal:" + (a*5).ToString() <<endl;

	cout <<"a / b equal:";

	try{
			cout << (a / b).ToString() <<endl;
		}
		catch (const invalid_argument err){
			cout << err.what();
			return 1;
	}

	cout <<"module of a equal:\n";
	cout << a.modul() << endl;

	cout <<"argument of b equal:\n";
	cout << b.argum() << endl;
}