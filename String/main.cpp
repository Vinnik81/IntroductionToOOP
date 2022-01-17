#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(const char* str);
class String;
String operator+(const String& left, const String& right);

class String
{
	int size;        //Размер строки
	char* str;		//Указатель на строку в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	char* get_str()const
	{
		return str;
	}
	 explicit String(int size = 80)
	{
		 //Благодаря принимаемому параметру size мы можем создавать строки заданного размера
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConst: \t" << this << endl;
	}
	 String(const char* str)
	 {
		 //cout << sizeof("Hello") << endl;
		 this->size = StringLength(str) + 1;	//Сохраняем размер строки в Байтах, с учетом Терминирующего нуля.
		 this->str = new char[size] {};
		 for (int i = 0; i < size; i++)this->str[i] = str[i];
		 cout << "Const:\t" << this << endl;
	 }
	 String(const String& other)
	 {
		 //Глубокое копирование (Deep copy)
		 this->size = other.size;
		 this->str = new char[size] {};
		 for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		 cout << "CopyConstr: " << this << endl;
	 }
	~String()
	{
		delete this->str;		//Если конструктор выделяет память при помощи оператора new,
		//то деструктор обязательно должен освобождать эту память оператором delete[],
		//в противном случае будет возникать утечка памяти.
		cout << "Destr:\t" << this << endl;
	}
	                 //					operators:
	String& operator=(const String& other)
	{
		if (this == &other)return*this;
		delete[] this->str;
		//Глубокое копирование (Deep copy)
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssign:\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	      //							Methods:
	void print() const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define NULL_TERMINATED_LINES
//#define BASE_CHEK
#define HOME_WORK
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
const char* str1 = "World";
str1[2] = 0;*/
	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	//SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
#endif //  NULL_TERMINATED_LINES
#ifdef BASE_CHEK
	String str1;
	str1.print();
	//String str2 = 25; обычный конструктор		Преобразование int в String запрещено при помощи explicit
	String str2(25); //explicit конструктор можно вызвать только так
	str2.print();
	cout << sizeof("Hello") << endl;
	cout << "StringLength: " << StringLength("Hello") << endl;
	String str3 = "Hello";
	str3.print();
	str3 = str3;
	String str4 = str3; //CopyConstr
	str4.print();
	String str5;
	str5 = str4;	//CopyAssignment
	str5.print();
#endif // BASE_CHEK

#ifdef HOME_WORK
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	str3 = str1 + str2;
	cout << "\n" << str3 << endl;
	cout << "\n================================" << endl;
	str1 += str2;
	cout << "\n" << str1 << endl;
	cout << "\n================================" << endl;
#endif // HOME_WORK

}
int StringLength(const char* str)
{
	//Считает размер строки в символах, т.е., без учета Терминирующего нуля
	int i = 0;
	for (; str[i]; i++);
	return i;
}