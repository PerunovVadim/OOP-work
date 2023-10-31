//автор - Перунов Вадим ИВТ-22
#include <iostream>
#include "ComplexNumber.h"

using namespace std;

void complex_out(ComplexNumber a){
	if (a.real != 0 and a.imag != 0)
		cout << "z = " << a.real << " + " << a.imag <<"i\n" << endl;
	if (a.imag == 0)
		cout << "z = " << a.real << "\n" << endl;
	if (a.real == 0 and a.imag != 0)
		cout << "z = " << a.imag << "i\n" << endl;
}

int main(){
	ComplexNumber a(5,9),b(4,3),c;

	cout <<"Value of a:\n";
	complex_out(a);

	cout <<"Value of b:\n";
	complex_out(b);

	cout <<"Value of c:\n";
	complex_out(c);

	c = b;
	cout <<"c = b:\n";
	complex_out(c);

	cout <<"a + b equal:" + (a+b).ToString() <<endl;

	cout <<"a - b equal:" + (a-b).ToString() <<endl;

	cout <<"a * b equal:" + (a*b).ToString() <<endl;

	cout <<"a * 5 equal:" + (a*5).ToString() <<endl;

	cout <<"a / b equal:";

	try{
			cout << (a / b).ToString() <<endl;
		}
		catch (const runtime_error err){
			cout << err.what();
			return 1;
	}

	cout <<"module of a equal:\n";
	cout << a.modul() << endl;

	cout <<"argument of b equal:\n";
	cout << b.argum() << endl;
}