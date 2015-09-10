#include <iostream>

using namespace std;

void input(int&, int&);
int conv(int, int);
void op(int, int, char);
char m;

int main()
{
	int hr12, hr24, min24;
	cout << "Program for time format change" << endl;

	input(hr24, min24);

	hr12 = conv(hr24, min24);
	op(hr12, min24, m);
	return 0;
}

void input(int& hr, int& min)
{
	cout << "enter the hours for 24 hr format :\n";
	cin >> hr;
	cout << "enter the minutes for 24 hr format :\n";
	cin >> min;

}

int conv(int hr24, int min24)
{
	int h12;
	if (hr24 >= 12){
		h12 = hr24-12;
		if (min24 >= 1)
			m = 'P';
		else
			m = 'A';
	}
	return (h12);
}

void op(int hr12, int min24, char a)
{
	cout << "the time in 12hr format is : " << hr12 << ":" << min24 << endl;
	cout << "And the meridian is : " << a << endl;
}
