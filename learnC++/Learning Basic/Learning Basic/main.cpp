#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	float cels, kelvin, fahr;

	cout << "Input the temperature in Fahrenheit: ";
	cin >> fahr;

	cels = (5.0 / 9.0) * (fahr - 32.0);
	kelvin = cels + 273.15;

	cout << "The temp in Celsius is: " << cels << endl;
	cout << "The temp in Kelvin is " << kelvin << endl;
}