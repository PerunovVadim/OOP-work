#include <cmath>
#include <stdexcept>
#include <string>
#include <sstream>
#include "ComplexNumber.h"

/// конструктор без указания нач. значений ( поля в таком случае равны 0)
ComplexNumber::ComplexNumber(){
	real = 0;
	imag = 0;
}
/// конструктор с указанием начальных значений r и i
ComplexNumber::ComplexNumber(double r, double i){
	real = r;
	imag = i;
}

///присваивает значение r действ. части числа
void ComplexNumber::set_real(double r){
	real = r;
}
///присваивает значение  i мнимой. части числа
void ComplexNumber::set_imag(double i){
	imag = i;
}
///присваивание комплексному числу значение комплекс. числа ComNum
void ComplexNumber::operator = (ComplexNumber ComNum){
	real = ComNum.real;
	imag = ComNum.imag;
}

///сложение комплексного числа с комплекс. числом add
ComplexNumber ComplexNumber::operator + (ComplexNumber add) const{
	ComplexNumber summ; //сумма двух комплексных чисел
	summ.real = real + add.real;
	summ.imag = imag + add.imag;
	return summ;
}
///вычитание из комплексного числа комплексного числа sub
ComplexNumber ComplexNumber::operator - (ComplexNumber sub) const{
	ComplexNumber diff; //разность двух комплексных чисел
	diff.real = real - sub.real;
	diff.imag = imag - sub.imag;
	return diff;
}
///деление комплексного числа на комплексное число divi
ComplexNumber ComplexNumber::operator / (ComplexNumber divi) const{
	ComplexNumber divide; //результат деления двух комплексных чисел
	if (divi.real == 0 and divi.imag == 0){   //если делитель равен 0, то функция кидает исключение
		throw std::invalid_argument("Invalid argument - zero divisor");
	}
	else{
		divide.real = (real * divi.real + divi.imag * imag) /(divi.real*divi.real + divi.imag*divi.imag);
		divide.imag = (imag * divi.real + divi.imag * real) /(divi.real*divi.real + divi.imag*divi.imag);
		return divide;
	}
}
///умножение комплексного числа на комплексное число mul
ComplexNumber ComplexNumber::operator * (ComplexNumber mul) const{
	ComplexNumber mult;//результат произведения двух комплексных чисел
	mult.real = real * mul.real - mul.imag * imag;
	mult.imag = (imag * mul.real + mul.imag * real);
	return mult;
}
///умножение комплексного числа на действ. число mul
ComplexNumber ComplexNumber::operator * (double mul) const{
	ComplexNumber mult;//результат умножения комплексного числа на действительное
	mult.real = real * mul;
	mult.imag = imag * mul;
	return mult;
}
///нахождение модуля комплексного числа
double ComplexNumber::modul() const{
	return sqrt(real*real + imag*imag);
}
///нахождение аргумента комплексного числа
double ComplexNumber::argum()  const{
	if (real > 0)
		return atan(imag/real) *(180/pi);
	if (real < 0 and imag >= 0)
		return (pi + atan(imag/real))*(180/pi);
	if (real < 0 and imag < 0)
		return (-pi + atan(imag/real))*(180/pi);
	if (real == 0 and imag > 0)
		return 90;
	if (real == 0 and imag < 0)
		return -90;
	return 0;
}

std::string ComplexNumber::ToString() const{
	std::stringstream ss;

	if (real != 0 and imag != 0){
		ss << "z = " << real << '+' << imag << "i\n";
		return ss.str();
	}
	if (imag == 0){
		ss << "z = " << real << '\n';
		return ss.str();
	}
	if (real == 0 and imag != 0){
		ss << "z = " << imag << "i\n";
		return ss.str();
	}
}