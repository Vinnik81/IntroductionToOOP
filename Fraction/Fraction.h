#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Fraction;
Fraction operator+(Fraction left, Fraction rigth);
Fraction operator-(Fraction left, Fraction rigth);
Fraction operator*(Fraction left, Fraction rigth);
Fraction operator/(Fraction left, Fraction rigth);
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);
bool operator==(const Fraction& left, const Fraction& rigth);
bool operator!=(const Fraction& left, const Fraction& rigth);
bool operator>(const Fraction& left, const Fraction& rigth);
bool operator<(const Fraction& left, const Fraction& rigth);
bool operator>=(const Fraction& left, const Fraction& rigth);
bool operator<=(const Fraction& left, const Fraction& rigth);

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//       Конструктора:
	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(double decimal);
	Fraction(const Fraction& other);
	~Fraction();
	//    Операторы:
	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator++();
	Fraction& operator++(int);
	Fraction& operator--();
	Fraction& operator--(int);
	explicit operator int()const;
	explicit operator double()const;

	//             Методы:
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction inverted();
	Fraction& reduce();
	void print()const;
};