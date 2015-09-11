// Program for converting feet & inches to Meters and Centimeters
#include <iostream>
using namespace std;

void input(int& ,int&);														// function for taking input from user
int conv(int, int, int&, int&);												// for converting to meter and cm
void output(int, int);														// printing on the screen
char end = 's';

int main(){
	int ft, in, mt, cm;
	cout << "Program for converting feet & inches to Meters and Cm " << endl;
	do{
		input(ft, in);														// a do-while loop: run the code till the user wants, exit if pressed 'e'
		conv(ft, in, mt, cm);
		output(mt, cm);
	}while (end != 'e');													// check the user input: if 'e' exit the loop
	return 0;
}

void input(int& ft, int& in){
	cout << "enter the length of Feet :" << endl;
	cin >> ft;
	cout << "enter the length of Inches :" << endl;
	cin >> in;
}

int conv(int ft, int in, int& mt, int& cm){
	int c;
	c = (ft * 0.3048)*1000;
	mt = c/1000;
	cm = c%1000;
	return 0;
}

void output(int mt, int cm){
	cout << "the value in meters is :" << mt << endl;
	cout << "the value in CentiM is :" << cm << endl;
	cout << "Press 'e' to end and s to continue :" << endl;
	cin >> end;
}
