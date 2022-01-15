#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(const char* str);

class String
{
	int size;
	char* str;
public:
	 explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConst: \t" << this << endl;
	}
	 String(const char* str)
	 {
		 //cout << sizeof("Hello") << endl;
		 this->size = StringLength(str) + 1;
		 this->str = new char[size] {};
		 for (int i = 0; i < size; i++)this->str[i] = str[i];
		 cout << "Const:\t" << this << endl;
	 }
	 String(const String& other)
	 {
		 this->size = other.size;
		 this->str = new char[size] {};
		 for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		 cout << "CopyConstr: " << this << endl;
	 }
	~String()
	{
		delete this->str;
		cout << "Destr:\t" << this << endl;
	}
	                 // operators:
	String& operator=(const String& other)
	{
		if (this == &other)return*this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssign: " << this << endl;
		return *this;
	}

	      //Methods:
	void print() const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};
//#define NULL_TERMINATED_LINES
#define BASE_CHEK
void main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#ifdef  NULL_TERMINATED_LINES
	/*char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };*/
/*char str[] = "Hello";
cout << str << endl;
str[2] = 0;
cout << str << endl;
const char* str1 = "World";*/
	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "¬ведите строку: ";
	//SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
#endif //  NULL_TERMINATED_LINES
#ifdef BASE_CHEK
	String str1;
	str1.print();
	//String str2 = 25; обычный конструктор
	String str2(25); //explicit конструктор
	str2.print();
	cout << sizeof("Hello") << endl;
	cout << "StringLength: " << StringLength("Hello") << endl;
	String str3 = "Hello";
	str3.print();
	str3 = str3;
	String str4 = str3; //CopyConstr
	str4.print();
	String str5;
	str5 = str4;
	str5.print();
#endif // BASE_CHEK

}
int StringLength(const char* str)
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}