// program to calculate the gross salary after deducting the taxes and other costs
#include <iostream>
using namespace std;

int main()
{
	cout << "Hello World !!";
	float gross, sst, ft, st, sal;						// define the varables
	int hrs, dep, oh;
	cout << "enter the number of dependents :\n";		// input the dependents
	cin >> dep;
	cout << "enter the number of hours worked :\n";		// input the hours worked
	cin >> hrs;
	if (hrs > 40) {										// check if overtime
		oh = hrs - 40;
		sal = (16.78*1.5*oh) + 16.78*hrs;				// calculate overtime salary
	}
	else {
		sal = 16.78*hrs;								// else calculate normal base salary
	}
	if (dep > 3) {
		sal = sal - 35;									// add some $35 if dependents
	}
	sst = sal * 0.06; ft = sal * 0.14; st = sal * 0.05;	//
	gross = sal - sst - ft - st - 40;					// calculate take home salary
	cout << "the take home salary is:" << (gross * 4);	// print it
	return 0;
}

