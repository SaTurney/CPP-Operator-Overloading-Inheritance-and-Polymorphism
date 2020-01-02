//File Name: Shapes.cpp
//Created By: Sabrina Turney
//Created On: June 19, 2019
//Program Purpose: To demonstrate operator overloading, inheritance, and polymorphism by utilizing a class hierarchy of shapes


#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;


/******************Rectangle Class****************************/
//class declaration section
class Rectangle
{
protected:
	//data members	
	int sideA; //size of one side of the rectangle
	int sideB; //size of the second side of the rectangle
public:
	Rectangle(int, int);
	void setSideA(int); //set the size of the first side
	void setSideB(int); //set the size of the second side
	int getSideA();     //get the size of the first side
	int getSideB();     //get the size of the second side
	int computePerimeter(); //will return the perimeter
	int computeArea();  //will return the area 
	void operator++(int); //overloaded increment operator
	void operator--(int); //overloaded decrement operator
	bool operator==(Rectangle &); //overloaded "is equal to" operator
};

//Constructor. Makes the user set values for all variables
//Using the setter functions ensures the user cannot set invalid values.
Rectangle::Rectangle(int sideA, int sideB)
{
	setSideA(sideA);
	setSideB(sideB);
}

//sets the size of SideA
void Rectangle::setSideA(int sizeA)
{
	if (sizeA <= 0)	//cannot have size of 0 units.
		sideA = 1;  //will default to 1 in the case of 0 or negatives.
	else sideA = sizeA;
}

//sets the size of SideB
void Rectangle::setSideB(int sizeB)
{
	if (sizeB <= 0) //cannot have a size of 0 units.
		sideB = 1; //will default to 1 in the case of 0 or negatives.
	else sideB = sizeB;
}

//returns the size of SideA
int Rectangle::getSideA()
{
	return sideA;
}

//returns the size of SideB
int Rectangle::getSideB()
{
	return sideB;
}

//computes the perimeter of the rectangle
int Rectangle::computePerimeter()
{
	return 2 * (sideA + sideB);
}

//computes the area of the rectangle
int Rectangle::computeArea()
{
	return sideA * sideB;
}

//increment operator
void Rectangle::operator++(int)
{
	this->sideA++;
	this->sideB++;
}

//decrement operator
void Rectangle::operator--(int)
{
	this->sideA--;
	this->sideB--;
}

//operator "is equal to" overload. If all members are equal, then returns true.
//Also allows different methods of protected members access when in local instances.
//I used this as a takeaway from the cars.cpp code, then changed it for this project.

bool Rectangle::operator==(Rectangle& rectangle)
{
	if ( (getSideA() == rectangle.getSideA()) && (this->sideB == rectangle.getSideB()))
		return true;
	else return false;
}


/******************Square Class****************************/
//class declaration section
class Square : public Rectangle
{
public:			     //making sure it doesn't default to private
	Square(int);     //constructor
	void setSideA(int);
	void setSideB(int);
};

//Square contstructor. Assuming all squares have equal length sides.
//Need to demonstrate how this constructor will match the parent (Rectangle) constructor
Square::Square(int sideA) : Rectangle(sideA, sideA)
{

}

//For Square, both sides are equal. Both sides are changed here to be equal.
void Square::setSideA(int size)
{
	if (size <= 0) //again preventing negative or zero sizes for the sides.
		size = 1;
	sideA = size; //Setting both sides to equal numbers, because squares are equal on all sides.
	sideB = size;
}

void Square::setSideB(int size)
{
	if (size <= 0)
		size = 1;
	sideA = size; //Setting both sides to equal numbers, because squares are equal on all sides.
	sideB = size;
}

void displayData(Rectangle); // function prototype

int main()
{
	//Declare variables
	int inpsideA;  //Allows user to input value for side A
	int inpsideB;  //Allows user to input value for side B

	cout << "Testing the Square Class" << endl;
	cout << "Enter length of side: ";
	cin >> inpsideA;
	Square ss(inpsideA);
	displayData(ss); //Displays the first values of the Square

	ss.operator++(1);  //using operator increment to add 1 to square value


	cout << "\nAfter calling the increment operator" << endl;
	displayData(ss); //Displays new values of Square


	cout << "\nTesting the Rectangle Class" << endl;
	cout << "Enter length of first side: ";
	cin >> inpsideA;
	cout << "Enter length of second side: ";
	cin >> inpsideB;
	Rectangle rr(inpsideA, inpsideB);
	displayData(rr); //Displays first values of Rectangle

	rr.operator--(1); //using operator decrement to subtract 1 from rectangle value
	

	cout << "\nAfter calling the decrement operator" << endl;
	displayData(rr);
	{
		if ((rr.getSideA() == ss.getSideA()) && (ss.getSideB() == rr.getSideB()))
			cout << "\nThe two objects have equal sides";
		else cout << "\nThe two objects are not equal in size";
	}
}

/****************************************************************************/
/* Because of inheritance and polymorphism the displayData function can be
   passed either a Rectangle object or a Square object to display each
   object's data.                                                           */
void displayData(Rectangle shape)
{
	cout << "\nThe length of side A is " << shape.getSideA() << endl;
	cout << "The length of side B is " << shape.getSideB() << endl;
	cout << "The perimeter is " << shape.computePerimeter() << endl;
	cout << "The area is " << shape.computeArea() << endl << endl;
}