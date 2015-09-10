/*#include <stdio.h>
#include <stdlib.h>
void fun(int *p1, int *p2);
int main()
{
	int N1=10;
	int N2=20;
	printf("Before Swapping\n");
	printf("N1:%d N2:%d\n", N1, N2);
	fun(&N1, &N2);
	printf("Before Swapping\n");
	printf("N1:%d N2:%d\n", N1, N2);
	system("PAUSE");
	return 0;
}
void fun(int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

#include <stdio.h>
#include <stdlib.h>

char check(int *day, int *mnth, int *year);

int main()
{
	int mnth = 0, day = 0, year = 0;
	char ans;

	printf("Program to check the DOB for Facebook !! \n");
	printf("Enter the date of birth");
	scanf("%d", &day);
	printf("Enter the month of birth");
	scanf("%d", &mnth);
	printf("Enter the year of birth");
	scanf("%d", &year);

	ans = check(&day, &mnth, &year);
	if(ans == 'P')
		printf("the person is valid to have a Facebook account");
	else
		printf("sorry you cannot make a Facebook account");

	return 0;
}

char check(int *day, int *mnth, int *year)
{
	//int suc = -1;
	if(*year >= 1997)
		if(*mnth >= 9)
			if(*day >= 2)
				return 'P';
			else
				return 'N';
		else
			return 'N';
	else
		return 'N';

}*/

#include <stdio.h>
#include <stdbool.h>

float avg(int *);
void even(int *);
void eadd(int *);
void rev(int *);
void prime(int *);
void hexx(int *);

int main()
{
	int arr[] = {10,11,12,13,15};
	float average = 0;
	average = avg(arr);
	even(arr);
	eadd(arr);
	printf("the average of all the element si: %f\n",average);
	rev(arr);
	prime(arr);
	hexx(arr);
	return 0;
}

float avg(int *a){
	float b = 0, av = 0;
	int i;
	for (i=0; i<5;i++)
	{
		av = av+a[i];
	}
	b = av/5;
	return b;
}

void even(int *a)
{
	int i= 0;
	for(i =0;i<5;i++)
	{
		if(i%2)
			printf("arr[%d] is an odd position \n", i);
		else
			printf("arr[%d] is an even position \n", i);
	}
}

void eadd(int *a){
	int ead = 0, od = 0;
	int i;
	for(i =0;i<5;i++)
	{
		if(i%2)
			od = od+a[i];
		else
			ead = ead+a[i];
	}
	printf("The sum of even values is: %d \n", ead);
	printf("The sum of odd values is: %d \n", od);
}

void rev(int *a)
{
	int rrr[5];
	int r = 0,i = 0;
	for (i = 0, r = 4; i<5 && r>-1; i++, r--)
	{
		rrr[r] = a[i];
	}

	printf(" The reversed array is as follows: \n");
	for (r=0; r<5;r++)
		printf(" a[%d] : %d\n", r, rrr[r]);
}

void prime(int *a)
{
	int i = 0, count = 0;
	for(i=0;i<5;i++){
		if(a[i]%2){
			if(a[i]%3){
				count++;
				//printf("  %d is a Prime number \n", a[i]);
			}
			else
				printf("  %d is Not a prime number \n", a[i]);
		}

		else
			printf("  %d is Not a prime number \n", a[i]);
		}
	printf(" There are %d prime numbers in the array \n", count);
}

void hexx(int *a)
{
	int i = 0, h[5];
	//byte hh = 0x00;
	for (i = 0;i<5;i++)
	{
		h[i] = a[i];
		printf("The Hex value of h[%d] is : %X \n", i, h[i]);
	}
}
