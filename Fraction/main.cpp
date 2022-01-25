#include"Fraction.h"

//#define OPERATORS_CHEK
//#define ARITHMETIC_CHEK
#define CONVERTING_DECIMAL_TO_NORMAL

void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);
	setlocale(LC_ALL, "");
#ifdef  OPERATORS_CHEK
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
	cout << "Q.to_improper = "; Q.print();
	cout << " = "; Q.to_improper(); Q.print();
	cout << "\n=============================================\n";
	cout << "R.to_proper = "; R.print();
	cout << " = "; R.to_proper(); R.print();
	cout << "\n=============================================\n";
	cout << "R.reduce = "; R.reduce(); R.print();
	cout << "\n=============================================\n";
	cout << "Fraction_1 == Fraction_2 ? = ";
	cout << (Fraction(1, 2) == Fraction(3, 5));
	cout << "\n=============================================\n";
	cout << "Fraction_1 != Fraction_2 ? = ";
	cout << (Fraction(1, 2) != Fraction(3, 5));
	cout << "\n=============================================\n";
	cout << "Fraction_1 > Fraction_2 ? = ";
	cout << (Fraction(1, 2) > Fraction(3, 5));
	cout << "\n=============================================\n";
	cout << "Fraction_1 < Fraction_2 ? = ";
	cout << (Fraction(1, 2) < Fraction(3, 5));
	cout << "\n=============================================\n";
	cout << "Fraction_1 >= Fraction_2 ? = ";
	cout << (Fraction(1, 2) >= Fraction(3, 5));
	cout << "\n=============================================\n";
	cout << "Fraction_1 <= Fraction_2 ? = ";
	cout << (Fraction(1, 2) <= Fraction(3, 5));
	cout << "\n=============================================\n";
	Fraction S(3, 4, 5); cout << "S = "; S.print(); cout << " ";
	cout << "\n=============================================\n";
	Fraction S2 = S++;
	S2.print(); cout << " S2 = S++ "; S.print();
	cout << "\n=============================================\n";
	Fraction S3 = ++S;
	S3.print(); cout << " S3 = ++S "; S.print();
	cout << "\n=============================================\n";
	Fraction S4 = S--;
	S4.print(); cout << " S4 = S-- "; S.print();
	cout << "\n=============================================\n";
	Fraction S5 = --S;
	S5.print(); cout << " S5 = --S "; S.print();
#endif //  OPERATORS_CHEK

#ifdef ARITHMETIC_CHEK
	Fraction A;
	Fraction B;
	cout << "Введите первую дробь: \n"; cin >> A;
	cout << "Введите вторую дробь: \n"; cin >> B;
	cout << endl;
	Fraction C = A * B;
	cout << A << " * " << B << " = " << C << endl;
	cout << "=============================================\n";
	Fraction D = C++;
	cout << D << " =>++ " << C << endl;
	cout << "=============================================\n";
	Fraction E = ++C;
	cout << E << " ++=> " << C << endl;
	cout << "=============================================\n";
	Fraction F = C--;
	cout << F << " =>-- " << C << endl;
	cout << "=============================================\n";
	Fraction G = --C;
	cout << G << " --=> " << C << endl;
	cout << "=============================================\n";
#endif // ARITHMETIC_CHEK

#ifdef CONVERTING_DECIMAL_TO_NORMAL
	double a;
	cout << "===============================================\n";
	cout << "Введите десятичную дробь: "; cin >> a;
	Fraction A = a;
	cout << a << " = " << A << endl;
	cout << "===============================================\n";
#endif // CONVERTING_DECIMAL_TO_NORMAL


}