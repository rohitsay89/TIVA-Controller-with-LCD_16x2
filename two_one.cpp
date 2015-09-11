/*
 * This code is for chap two exercise prob one
 * this code is to find the inflated rate of a product after a time pertiod depending on present value and inflation interest
 */
#include <iostream>

using namespace std;

int main()
{
	int cp, years;
	float rate, ep, inf;

	cout << "Enter the rate of inflation \n"; // input the data
	cin >> rate;
	cout << "Enter the number of years \n";// input the data
	cin >> years;
	cout << "Enter the price of one item \n";// input the data
	cin >> cp;

	inf = cp +(cp*rate)/100;
	// find the inflation according to the inflation rate on cost price
	ep = 200*inf*0.01*rate*years;
	// find the total price
	cout << "the estimated price is as follows: \n" << ep; //output the result
	return 0;
}

