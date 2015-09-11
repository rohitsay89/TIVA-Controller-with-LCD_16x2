 // Program to find the aggregate score of a student
#include <iostream>
using namespace std;

struct ScoreCard{				// define the structure for a student
	int me, fe, pt, q1, q2; 	// variable of points obtained
	char grade;					// grade
};

int main()
{
	float tscore;
	ScoreCard score;			// structure variable
	cout << "Pregram for score record of a student \n";
	cout << "Enter the midterm exam points out of 100 : \n";					// input the values of marks
	cin >> score.me;
	cout << "Enter the Final exam points out of 100 : \n";
	cin >> score.fe;
	cout << "Enter the Quiz 1 points out of 10 : \n";
	cin >> score.q1;
	cout << "Enter the Quiz 2 points out of 10: \n";
	cin >> score.q2;

	tscore = (score.me*0.25) + (score.fe*0.50) + ((score.q1+score.q2)*0.25);	// calculate the overall aggregate score
	cout << "The final score is as follows :\n" << tscore;						// print it on the console
	return 0;
}
