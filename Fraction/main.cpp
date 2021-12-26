﻿#include <iostream>
using namespace std;

class Fraction;
Fraction operator+(Fraction left, Fraction rigth);
Fraction operator-(Fraction left, Fraction rigth);
Fraction operator*(Fraction left, Fraction rigth);
Fraction operator/(Fraction left, Fraction rigth);

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator <= 0) denominator = 1;
		this->denominator = denominator;
	}
	                 //       Конструктора:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "\nDefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleargConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor_2:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "\nCopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "\nDestructor:\t" << this << endl;
	}
	//    Операторы:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	//             Методы:
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted()
	{
		to_improper();
		return Fraction(denominator, numerator);
	}
	Fraction& reduce()
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
	void print()const
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
};
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
//
void main()
{
	setlocale(LC_ALL, "");
	cout << "=============================================\n";
	Fraction A(3, 9);
	cout << "A = "; A.print();
	cout << "\n=============================================\n";
	Fraction B(4, 9);
	cout << "B = "; B.print();
	cout << "\n=============================================\n";
	cout << "A + B = "; (A + B).print();
	cout << "\n=============================================\n";
	Fraction C(2, 9);
	cout << "C = "; C.print();
	cout << "\n=============================================\n";
	Fraction D(1, 9);
	cout << "D = "; D.print();
	cout << "\n=============================================\n";
	cout << "C += D "; (C += D).print();
	cout << "\n=============================================\n";
	Fraction E(4, 6);
	cout << "E = "; E.print();
	cout << "\n=============================================\n";
	Fraction F(2, 8);
	cout << "F = "; F.print();
	cout << "\n=============================================\n";
	cout << "E - F = "; (E - F).print();
	cout << "\n=============================================\n";
	Fraction G(4, 6);
	cout << "G = "; G.print();
	cout << "\n=============================================\n";
	Fraction H(2, 8);
	cout << "H = "; H.print();
	cout << "\n=============================================\n";
	cout << "G -= H "; (G -= H).print();
	cout << "\n=============================================\n";
	Fraction I(1, 5);
	cout << "I = "; I.print();
	cout << "\n=============================================\n";
	Fraction J(2, 9);
	cout << "J = "; J.print();
	cout << "\n=============================================\n";
	cout << "I * J = "; (I * J).print();
	cout << "\n=============================================\n";
	Fraction K(6, 9);
	cout << "K = "; K.print();
	cout << "\n=============================================\n";
	Fraction L(3, 4);
	cout << "L = "; L.print();
	cout << "\n=============================================\n";
	cout << "K *= L "; (L *= K).print();
	cout << "\n=============================================\n";
	Fraction M(5, 6);
	cout << "M = "; M.print();
	cout << "\n=============================================\n";
	Fraction N(4, 9);
	cout << "N = "; N.print();
	cout << "\n=============================================\n";
	cout << "M / N = "; (M / N).print();
	cout << "\n=============================================\n";
	Fraction O(5, 6);
	cout << "O = "; O.print();
	cout << "\n=============================================\n";
	Fraction P(4, 9);
	cout << "P = "; P.print();
	cout << "\n=============================================\n";
	cout << "O /= P "; (O /= P).print();
	cout << "\n=============================================\n";
	Fraction Q(30, 10, 15);
	Fraction R(30, 8);
	cout << "Q = "; Q.print();
	cout << " = "; Q.to_improper(); Q.print();
	cout << "\n=============================================\n";
	cout << "R = "; R.print();
	cout << " = "; R.to_proper(); R.print();
	cout << "\n=============================================\n";
	cout << "R.reduce = "; R.reduce(); R.print();
	cout << "\n=============================================\n";
	cout << (Fraction(1,2) == Fraction(3,5)) << endl;
	cout << "\n=============================================\n";
	cout << (Fraction(1,2) != Fraction(3,5)) << endl;
	cout << "\n=============================================\n";
	cout << (Fraction(1,2) > Fraction(3,5)) << endl;
	cout << "\n=============================================\n";
	cout << (Fraction(1,2) < Fraction(3,5)) << endl;
	cout << "\n=============================================\n";
	cout << (Fraction(1,2) >= Fraction(3,5)) << endl;
	cout << "\n=============================================\n";
	cout << (Fraction(1,2) <= Fraction(3,5)) << endl;
	cout << "\n=============================================\n";
}