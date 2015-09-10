#include <iostream>

using namespace std;

struct ScoreCard{
	int me, fe, pt, q1, q2;
	char grade;

};

int main()
{
	float tscore;
	ScoreCard score;
	cout << "Pregram for score record of a student \n";

	cout << "Enter the midterm exam points : \n";
	cin >> score.me;
	cout << "Enter the Final exam points : \n";
	cin >> score.fe;
	cout << "Enter the Quiz 1 points : \n";
	cin >> score.q1;
	cout << "Enter the Quiz 2 exam points : \n";
	cin >> score.q2;

	tscore = (score.me*0.25) + (score.fe*0.50) + ((score.q1+score.q2)*0.25);

	cout << "The final score is as follows :\n" << tscore;

	return 0;

}
