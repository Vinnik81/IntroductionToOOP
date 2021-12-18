#include <iostream>
using namespace std;
using std::cout;
#define tab "\t"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
    }
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	                  //     Consructor:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	};
	        //     Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}

	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}

	      //     Methods:
	double distance(const Point& other) const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};
double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(pow(x_distance, 2) + pow(y_distance, 2));
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

//#define CONSTRUCTORS_CHECK
//#define StRUCT_POINT
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHEK
void main()
{
	setlocale(LC_ALL, "");
#ifdef  STRUCT_POINT
	int a;
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
#endif //  STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK
	Point A;
	double x, y;
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();

	Point B(22, 33);
	B.print();

	Point C = 5;
	C.print();

	Point D(0, 123);
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);
	cout << "----------------------------------------------------------------\n";
	cout << "Расстояние от точки 'А' до точки 'В': " << A.distance(B) << endl;
	cout << "----------------------------------------------------------------\n";
	cout << "Расстояние от точки 'B' до точки 'A': " << B.distance(A) << endl;
	cout << "----------------------------------------------------------------\n";
	cout << "Расстояние между 'A' и 'B': " << distance(A, B) << endl;
	cout << "----------------------------------------------------------------\n";
	cout << "Расстояние между 'B' и 'A': " << distance(B, A) << endl;
	cout << "----------------------------------------------------------------\n";
#endif // DISTANCE_CHECK
	//Point A(2, 3);
	//Point B = A; // CopyConstructor
	//B.print();
	//Point C; //DefaultConstructor
	//C = B;
	//C.print();
#ifdef ASSIGNMENT_CHEK
	Point A, B, C;
	cout << "\n--------------------------------\n";
	A = B = C = Point(7, 8);
	cout << "\n--------------------------------\n";
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHEK

	Point A(2, 3);
	Point B(7, 8);
	/*Point C = A + B;
	C.print();
	A += B;
	A.print();
	C++;
	C.print();*/
	A = B++;
	A.print();
	B.print();
	/*B.set_x(123);
	B.set_y(234);*/
	B(123, 234);
	B.print();
}