#include"Fraction.h"
#define DEBUG

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator <= 0) denominator = 1;
	this->denominator = denominator;
}
//       Конструктора:
Fraction::Fraction() :integer(0), numerator(0), denominator(1)
{

#ifdef DEBUG
	cout << "\nDefaultConstructor:\t" << this << endl;
#endif // DEBUG

}
Fraction::Fraction(int integer) :Fraction(integer, 0, 1)		//integer(integer), numerator(0), denominator(1)
{

#ifdef DEBUG
	cout << "SingleargConstructor:" << this << endl;
#endif // DEBUG

}
Fraction::Fraction(int numerator, int denominator) :Fraction(0, numerator, denominator)	//integer(0), numerator(numerator)
{
	set_denominator(denominator);
#ifdef DEBUG
	cout << "Constructor:\t" << this << endl;
#endif // DEBUG

}
Fraction::Fraction(int integer, int numerator, int denominator) :integer(integer), numerator(numerator)
{
	set_denominator(denominator);
#ifdef DEBUG
	cout << "Constructor_2:\t" << this << endl;
#endif // DEBUG


}
Fraction::Fraction(double decimal)   //преобразование десятичной дроби в обычную
{
	decimal += 1e-11;
	integer = decimal;
	denominator = 1e+9;
	decimal -= integer;
	numerator = decimal * denominator;
	reduce();
}
Fraction::Fraction(const Fraction& other) :integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{

#ifdef DEBUG
	cout << "\nCopyConstructor:\t" << this << endl;
#endif // DEBUG

}
Fraction::~Fraction()
{

#ifdef DEBUG
	cout << "\nDestructor:\t" << this << endl;
#endif // DEBUG

}
//    Операторы:
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;

#ifdef DEBUG
	cout << "CopyAssignment:\t" << this << endl;
#endif // DEBUG

	return *this;
}
Fraction& Fraction::operator+=(const Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction::operator-=(const Fraction& other)
{
	return *this = *this - other;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator++()    //Перегрузка инкремента (префиксная)
{
	integer++;
	return *this;
}
Fraction& Fraction::operator++(int)    //Перегрузка инкремента (постфиксная)
{
	Fraction post = *this;
	integer++;
	return post;
}
Fraction& Fraction::operator--()    //Перегрузка декремента (префиксная)
{
	integer--;
	return *this;
}
Fraction& Fraction::operator--(int)    //Перегрузка декремента (постфиксная)
{
	Fraction post = *this;
	integer--;
	return post;
}
Fraction::operator int()const
{
	return integer;
}
Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}

//             Методы:
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction Fraction::inverted()
{
	to_improper();
	return Fraction(denominator, numerator);
}
Fraction& Fraction::reduce()
{
	if (numerator == 0)
	{
		denominator = 1;
		return *this;
	}
	int bol, men, ost; //бльшее, меньшее значение и остаток для нохождение НОД
	if (numerator > denominator)
	{
		bol = numerator;
		men = denominator;
	}
	else
	{
		bol = denominator;
		men = numerator;
	}
	do
	{
		ost = bol % men;
		bol = men;
		men = ost;
	} while (ost);
	int GCF = bol; //НОД
	numerator /= GCF;
	denominator /= GCF;
	return to_proper();
}
void Fraction::print()const
{
	if (integer) cout << integer;
	if (numerator)
	{
		if (integer) cout << "(";
		cout << numerator << "/" << denominator;
		if (integer) cout << ")";
	}
	else if (integer == 0) cout << 0 << endl;
}

bool operator==(const Fraction& left, const Fraction& rigth)
{
	int res_1 = left.get_numerator() * rigth.get_denominator();
	int res_2 = left.get_denominator() * rigth.get_numerator();
	if (res_1 == res_2)return true;
	else return false;
}
bool operator!=(const Fraction& left, const Fraction& rigth)
{
	int res_1 = left.get_numerator() * rigth.get_denominator();
	int res_2 = left.get_denominator() * rigth.get_numerator();
	if (res_1 != res_2)return true;
	else return false;
}
bool operator>(const Fraction& left, const Fraction& rigth)
{
	int res_1 = left.get_numerator() * rigth.get_denominator();
	int res_2 = left.get_denominator() * rigth.get_numerator();
	if (res_1 > res_2)return true;
	else return false;
}
bool operator<(const Fraction& left, const Fraction& rigth)
{
	int res_1 = left.get_numerator() * rigth.get_denominator();
	int res_2 = left.get_denominator() * rigth.get_numerator();
	if (res_1 < res_2)return true;
	else return false;
}
bool operator>=(const Fraction& left, const Fraction& rigth)
{
	int res_1 = left.get_numerator() * rigth.get_denominator();
	int res_2 = left.get_denominator() * rigth.get_numerator();
	if (res_1 >= res_2)return true;
	else return false;
}
bool operator<=(const Fraction& left, const Fraction& rigth)
{
	int res_1 = left.get_numerator() * rigth.get_denominator();
	int res_2 = left.get_denominator() * rigth.get_numerator();
	if (res_1 <= res_2)return true;
	else return false;
}
Fraction operator+(Fraction left, Fraction rigth)
{
	Fraction result;
	if (left.get_denominator() == rigth.get_denominator())
	{
		result.set_integer(left.get_integer() + rigth.get_integer());
		result.set_numerator(left.get_numerator() + rigth.get_numerator());
		result.set_denominator(left.get_denominator());
	}
	else
	{
		result.set_integer(left.get_integer() + rigth.get_integer());
		result.set_numerator(left.get_numerator() * rigth.get_denominator() + rigth.get_numerator() * left.get_denominator());
		result.set_denominator(left.get_denominator() * rigth.get_denominator());
	}
	return result;
}
Fraction operator-(Fraction left, Fraction rigth)
{
	Fraction result;
	if (left.get_denominator() == rigth.get_denominator())
	{
		result.set_integer(left.get_integer() - rigth.get_integer());
		result.set_numerator(left.get_numerator() - rigth.get_numerator());
		result.set_denominator(left.get_denominator());
	}
	else
	{
		result.set_integer(left.get_integer() - rigth.get_integer());
		result.set_numerator(left.get_numerator() * rigth.get_denominator() - rigth.get_numerator() * left.get_denominator());
		result.set_denominator(left.get_denominator() * rigth.get_denominator());
	}
	return result;
}
Fraction operator*(Fraction left, Fraction rigth)
{
	left.to_improper();
	rigth.to_improper();
	return Fraction(left.get_numerator() * rigth.get_numerator(),
		left.get_denominator() * rigth.get_denominator()).to_proper();
}
Fraction operator/(Fraction left, Fraction rigth)
{
	return left * rigth.inverted();
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer()) cout << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) cout << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) cout << ")";
	}
	else if (obj.get_integer() == 0) cout << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)   // ввод дробей с клавиатуры
{
	int integer{}, numerator{}, denominator{};
	cout << "integer: "; cin >> integer;
	cout << "numerator: "; cin >> numerator;
	cout << "denominator: "; cin >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;
}