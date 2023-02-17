/*
Name: David Zheng
NetID: dz183

Program Description: This program is dessigned to give the hypotenuss.
It will ask the user for 3 inputs, upon which it will give the hypotenuse.
*/

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

//function declaration
void PythagreanTheorem(int Side_1, int Side_2, int Side_3);

//Start of the Program
int main()
{
	int Side_1;
	int Side_2;
	int Side_3;

	//Ask user for the sides
	cout << "Enter Side 1: ";
	cin >> Side_1;
	cout << "Enter Side 2: ";
	cin >> Side_2;
	cout << "Enter Side 3: ";
	cin >> Side_3;

	//These blocks below check for the hypotenuse and whether it is a right triangle.

	//Side 1 is hypotenuse
	if ((Side_1 > Side_2) && (Side_1 > Side_3)) 
	{
		PythagreanTheorem(Side_2, Side_3, Side_1);
	}

	//Side 2 is hypotenuse
	else if ((Side_2 > Side_1) && (Side_2 > Side_3))
	{
		PythagreanTheorem(Side_1, Side_3, Side_2);
	}

	//Side 3 is hypotenuse
	else if ((Side_3 > Side_1) && (Side_3 > Side_2))
	{
		PythagreanTheorem(Side_1, Side_2, Side_3);
	}

	//No hypotenuse or not a right triangle
	else
		cout << "A right triangle can not be formed with these sides" << endl;
}

//Pythagrean Theorem is a^2 + b^2 = c^2
void PythagreanTheorem(int Side_A, int Side_B, int Side_C)
{
	if (((Side_A * Side_A) + (Side_B * Side_B)) == (Side_C * Side_C))
		cout << "A right triangle can be formed with a hypotenuse of " << Side_C << endl;
	else
		cout << "A right triangle can not be formed with a hypotenuse of " << Side_C << endl;
}
