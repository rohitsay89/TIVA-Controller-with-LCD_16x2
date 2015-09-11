// program to calculate the Miles per Gallon efficiency of a vheical
// by having fuel quantity in Liters and
// distance driven in Miles

#include <iostream>

using namespace std;

float lpg;

int main()
{
	float mpg(float, float);  							// define variables

	float lit, gal, miles, m;  							// define variables
	cout << "Enter the number of liters of gas : \n"; 	// input the gas quantity
	cin >> lit;
	cout << "Enter the number of miles : \n"; 			// input the distance travelled
	cin >> miles;

	gal = lit*0.264179; 								// convert liters to gallons
	m = mpg(gal, miles); 								// calculate Miles per gallon from a function

	cout << "the miles per gallon value is : " << m;    // print the MPG on the screen
	return 0;
}

float mpg(float gal, float miles)
{
	return(miles/gal); 									// calculate and return the value of Miles per Gallon to the main function
}
