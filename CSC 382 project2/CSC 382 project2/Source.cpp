//heman zhang
//CSC382
//2/10/2018
//Project 2

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<limits>

using namespace std;

int Find(int, int A[], int);
int main()
{
	srand(time(NULL));
	int n = 50;

	int bound[] = { 30, 50, 80, 100, 1000, 10000, numeric_limits<int>::max() };
	int sequence[50];
	int boundNum = 0;
	double yes;
	double Calculated_Average, Real_Average;
	double q;
	cout << setw(8) << "Bound " << setw(23) << " Calculated Average" << setw(23) << " Real Average" << endl;
	while (boundNum < 7)
	{
		int x = rand() % bound[boundNum];
		int hits = 0;
		int total_steps = 0;
		for (int i = 0; i < 10000; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sequence[j] = rand() % bound[boundNum];

			}
			
				yes = Find(x, sequence, n);
				if (yes > 0)
				{
					hits++;
					total_steps = total_steps + yes;
				}
				else 
				{
					
					total_steps = total_steps + 50;
				}
			
			

		}
		cout << setprecision(4) << fixed << showpoint;
		q = hits / 10000.0;
		
		Calculated_Average = static_cast<double>(n)+(q / 2.0) - static_cast<double>(q*n) / 2.0;
		Real_Average = static_cast<double>( total_steps )/ 10000;
		if (boundNum == 6)
		{
			cout << setw(8) << "Infinity" << setw(18) << Calculated_Average << setw(25) << Real_Average << endl;
		}
		else
		cout << setw(5) << bound[boundNum] << setw(21) << Calculated_Average << setw(25) << Real_Average << endl;
		
		boundNum++;
	}

	return 0;

}
int Find(int x, int A[], int n) // array of size n
{
	int  j;
	for (j = 0; j < n; j++)
	{
		if (x == A[j])
		{
			return (j + 1); //the position is 1 more than the index
		}
	}
	return 0; // x is not an element of the array
}


/*OUTPUT
Bound   Calculated Average        Real Average
30             33.3645             28.7092
50             35.6945             33.3435
80             39.1196             38.0056
100             40.8297             40.1158
1000             48.8509             48.8214
10000             49.8873             49.8845
Infinity             49.9632             49.9663
Press any key to continue . . .

*/