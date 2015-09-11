// convert 24 hour fomrat to 12 hour fomrat
#include <iostream>
using namespace std;

void input(int&, int&);									// a function for inputting the values
int conv(int, int);										// a function for conversion
void op(int, int, char);								// for output
char m;

int main(){
	int hr12, hr24, min24;								// variables declaration
	cout << "Program for time format change" << endl;
	input(hr24, min24);									// passing the values to input function
	hr12 = conv(hr24, min24);							// converting
	op(hr12, min24, m);									// printing on the screen
	return 0;
}

void input(int& hr, int& min){
	cout << "enter the hours for 24 hr format :\n";
	cin >> hr;
	cout << "enter the minutes for 24 hr format :\n";
	cin >> min;
}

int conv(int hr24, int min24){
	int h12;
	if (hr24 >= 12){
		h12 = hr24-12;
		if (min24 >= 1)
			m = 'P';									// also  change the flag according to meridian
		else
			m = 'A';									// 'A' for AM and 'P' for PM
	}
	return (h12);
}

void op(int hr12, int min24, char a){
	cout << "the time in 12hr format is : " << hr12 << ":" << min24 << endl;
	cout << "And the meridian is : " << a << endl;		// print on the screen
}
