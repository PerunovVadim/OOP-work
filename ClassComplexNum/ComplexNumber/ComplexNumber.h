#ifndef ComplexNumber_h
#define ComplexNumber_h
#include <numbers>
using std::numbers::pi;

class ComplexNumber{
	public:
		double real; //действительная часть комплексного числа
		double imag; //мнимая часть комплексного числа
	
		/// конструктор без указания нач. значений ( поля в таком случае равны 0)
		ComplexNumber();

		/// конструктор с указанием начальных значений r и i
		ComplexNumber(double r, double i);

		///присваивает значение r действ. части числа
		void set_real(double r);

		///присваивает значение  i мнимой. части числа
		void set_imag(double i);

		///присваивание комплексному числу значение комплекс. числа ComNum
		void operator = (const ComplexNumber &ComNum);

		///сложение комплексного числа с комплекс. числом add
		ComplexNumber operator + (const ComplexNumber& add) const;//const после списка параметров определяет метод как константный, 
																  //т.е не изменяющий полей класса

		///вычитание из комплексного числа комплексного числа sub
		ComplexNumber operator - (const ComplexNumber& sub) const;//const после списка параметров определяет метод как константный, 
																  //т.е не изменяющий полей класса

		///деление комплексного числа на комплексное число divi
		ComplexNumber operator / (const ComplexNumber& divi) const;//const после списка параметров определяет метод как константный, 
																  //т.е не изменяющий полей класса

		///умножение комплексного числа на комплексное число mul
		ComplexNumber operator * (const ComplexNumber& mul) const;//const после списка параметров определяет метод как константный, 
																  //т.е не изменяющий полей класса

		///умножение комплексного числа на действ. число mul
		ComplexNumber operator * (double mul) const;//const после списка параметров определяет метод как константный, 
													//т.е не изменяющий полей класса

		///нахождение модуля комплексного числа
		double modul() const;//const после списка параметров определяет метод как константный, 
							 //т.е не изменяющий полей класса

		///нахождение аргумента комплексного числа
		double argum() const;//const после списка параметров определяет метод как константный, 
							 //т.е не изменяющий полей класса


		///выводит комплексное число в строку
		std::string ToString() const;//const после списка параметров определяет метод как константный, 
							 		 //т.е не изменяющий полей класса

};

void Complex_To_Text_File(ComplexNumber &a,const std::string &file_name);
void Complex_From_Text_File(ComplexNumber &a, const std::string &file_name);

#endif