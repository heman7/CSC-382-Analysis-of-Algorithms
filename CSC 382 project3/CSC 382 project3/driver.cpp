//Heman Zhang
//CSC382
//Professor Petingi
//Project 3
//3/6/2018
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

int Insertion(int A[], int );

int main()
{
	srand(time(NULL));
	
	int n[] = { 100, 500, 1000, 2500, 3000, 3500 };
	int bound=10000;
	int sequence[3600];
	double Calculated_Average, Real_Average;
	

	cout<<left <<setw(23) << "Input Size" << setw(30) << "Calculated Average" << setw(30) << "Real Average" << endl;

	for (int i = 0; i < 6;i++)
	{
		 long long int tot_number_steps=0;

		 sequence[n[i]];
				
		for (int j = 0; j < 100000; j++)
		{
			for (int k = 0; k < n[i]; k++)
			{
				sequence[k] = rand() % bound;

			}

			tot_number_steps += Insertion(sequence, n[i]);		

		}
		cout << setprecision(2)<<fixed;
		Calculated_Average = (pow(n[i], 2) / 4) + (3 * n[i] / 4);
		Real_Average = tot_number_steps / 100000.0;

		cout << left << setw(23) << n[i] << setw(30) << Calculated_Average << setw(30) << Real_Average << endl;
		}


		return 0;
}

int Insertion(int A[], int n) // in reality the elements to be sorted are indexed from index 1 to index n
{

	int steps = 0;
	int i, j, temp;
	A[0] = -32768; //smallest possible integer using 2 bytes integer representation
	for (i = 1; i <= n; i++) {
		j = i;
		 while (A[j] < A[j - 1]) { // swap 
			temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
			steps++; //comparisons which need to swap
		}
		 steps++;//comparisons which doesn't need to swap
	}
	return steps;
}


/*OUTPUT
Input Size             Calculated Average            Real Average
100                    2575.00                       2526.33
500                    62875.00                      62619.16
1000                   250750.00                     250186.12
2500                   1564375.00                    1562990.43
3000                   2252250.00                    2250503.63   
3500                   3075125.00                    3062907.72
Press any key to continue . . .*/


