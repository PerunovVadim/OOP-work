//автор - Перунов Вадим ИВТ-22
#include <iostream>
#include <cassert>
#include <cmath>
#include "ComplexNumber.h"

const double eps = 10e-3;
const unsigned int n = 8;//размер массивов
using namespace std;


int main(){

	ComplexNumber ch1(1,1),ch2(2,2);
	assert((abs((ch1+ch2).real - 3) <=eps) && (abs((ch1+ch2).imag - 3) <=eps));
	assert((abs((ch1-ch2).real + 1) <=eps) && (abs((ch1-ch2).imag + 1) <=eps));
	assert((abs((ch1*ch2).real - 0) <=eps) && (abs((ch1*ch2).imag - 4) <=eps));
	assert((abs((ch1/ch2).real - 0.5) <=eps) && (abs((ch1/ch2).imag) <=eps));
	assert((abs((ch1).argum() - 45) <=eps));
	assert((abs((ch2).modul() - 2.8284) <=eps));

	ComplexNumber a(5,9),c;
	ComplexNumber *b = new ComplexNumber(4,3); 

	cout <<"Value of a:" + (a).ToString() <<endl;

	cout <<"Value of b:" + (*b).ToString() <<endl;

	cout <<"Value of c:" + (c).ToString() <<endl;

	c = *b;
	cout <<"c = b:\n" << c.ToString();

	cout <<"a + b equal:" + (a+(*b)).ToString() <<endl;

	cout <<"a - b equal:" + (a-(*b)).ToString() <<endl;

	cout <<"a * b equal:" + (a*(*b)).ToString() <<endl;

	cout <<"a * 5 equal:" + (a*5).ToString() <<endl;

	cout <<"a / b equal:";

	try{
			cout << (a / (*b)).ToString() <<endl;
		}
		catch (const invalid_argument err){
			cout << err.what();
			return 1;
	}

	cout <<"module of a equal:\n";
	cout << a.modul() << endl;

	cout <<"argument of b equal:\n";
	cout << b->argum() << endl;

	//Динамический массив из обьектов класса и применение методов к элементам массива
	ComplexNumber* complex = new ComplexNumber[n];

	complex[0] = a;
	complex[1] = ComplexNumber(7,8);

	cout <<"Complex[0]: " << complex[0].ToString() << endl;

	cout <<"module of Complex[0] equal:\n";
	cout << complex[0].modul() << endl;

	cout <<"argument of Complex[1] equal:\n";
	cout << complex[1].argum() << endl;

	delete[] complex;

	//дин. массив указателей на обьекты класса ComplexNumber
	ComplexNumber* *complexP = new ComplexNumber*[n];
	complexP[0]=new ComplexNumber(5,6);

	cout <<"module of ComplexP[0] equal:\n";
	cout << complexP[0]->modul() << endl;

	cout <<"argument of ComplexP[0] equal:\n";
	cout << complexP[0]->argum() << endl;

	for (unsigned i = 0; i < n; i++)
		delete complexP[i];

	delete[] complexP;
}