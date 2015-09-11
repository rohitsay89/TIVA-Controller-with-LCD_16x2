// program to calculate calories burned using MET, weight and time of work out
#include <iostream>
#include <stdint.h>

using namespace std;

int main()
{
	float wt, cal;
	uint16_t  min;
	uint16_t mets = 0;
	cout << "enter the weight in pounds: \n";
	cin >> wt;
	cout << "enter the time in minutes: \n";
	cin >> min;
	cout << "enter the number of METs for the activity: \n";
	cin >> mets;
	cal = min*0.0175*mets*wt*0.45; // calculation of calories burned
	cout << "the calories burned = " << cal;
}
