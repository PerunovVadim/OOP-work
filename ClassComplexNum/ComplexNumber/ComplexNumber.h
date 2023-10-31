#ifndef ComplexNumber_h
#define ComplexNumber_h

const double pi = 3.14159265;
class ComplexNumber{
	public:
		double real; //действительная часть комплексного числа
		double imag; //мнимая часть комплексного числа
	
		/// конструктор с начальными значениями 0 и 0
		ComplexNumber();

		/// конструктор с указанием начальных значений r и i
		ComplexNumber(double r, double i);

		///присваивает значение r действ. части числа
		void set_real(double r);

		///присваивает значение  i мнимой. части числа
		void set_imag(double i);

		///присваивание комплексному числу значение комплекс. числа ComNum
		void operator = (ComplexNumber ComNum);

		///сложение комплексного числа с комплекс. числом add
		ComplexNumber operator + (ComplexNumber add) const;

		///вычитание из комплексного числа комплексного числа sub
		ComplexNumber operator - (ComplexNumber sub) const;

		///деление комплексного числа на комплексное число divi
		ComplexNumber operator / (ComplexNumber divi) const;

		///умножение комплексного числа на комплексное число mul
		ComplexNumber operator * (ComplexNumber mul) const;

		///умножение комплексного числа на действ. число mul
		ComplexNumber operator * (double mul) const;

		///нахождение модуля комплексного числа
		double modul() const;

		///нахождение аргумента комплексного числа
		double argum() const;

		///выводит комплексное число в строку
		std::string ToString() const;
};
#endif