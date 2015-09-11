/*
 * To calculate the approximate measurements of Hat Jacket and Waist by using Age, Height and Weight of a person
 */

#include <iostream>
#include <stdint.h>

using namespace std;

float hat(int, int);				// Define functions
float jack(int, int, int);
float waist(int, int);

int main()
{
	int age = 0, wlb = 0, Hti = 0; 				// declare variables

	cout << "Enter the height in inches: \n";
	cin >> Hti;
	cout << "Enter the weight in pounds: \n";
	cin >> wlb;
	cout << "Enter your age: \n";
	cin >> age;

	cout << "Hat size is :" << hat(wlb, Hti) << " Inches " << endl;
	cout << "Jacket size is : " << jack(Hti, wlb, age) << " Inches " << endl;
	cout << "Waist size is :" << waist(wlb, age) << " Inches " << endl;
	return 0;

}

float hat(int w, int h)
{
	float h1 = 0;
	h1 = static_cast<float>((w/h)*2.9);
	return (h1);
}

float jack(int h, int w, int a)
{
	uint16_t x = 0;
	float j1;
	if (a > 30)
		x = a/10;
	j1 = ((h*w)/288) + (x/8);
	return (j1);
}

float waist(int w, int a)
{
	int x = 0;
	float w1;
	if (a>28)
		x = ((a-28)/20);
	w1 = (w/5.7) + x;
	return w1;
}
