//Heman Zhang
//CSC382 
//Project 1
//2/4/2018

#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;

long int FiboR(int);
long int FiboNR(int);
int main()
{
	clock_t time,time2, t_recur, t_nonRecur;
	int n[] = { 1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60 };
	int i = 0;
	int Fibo_value;
	cout << "Integer" << setw(20) << " FiboR (seconds)" << setw(20) << "FiboNR(seconds)" << setw(20) << "Fibo-value" << endl;
	while (i <sizeof(n))
	{
		time = clock();
		 FiboR(n[i]);
		t_recur = clock() - time;

		time2 = clock();

		Fibo_value = FiboNR(n[i]);
		
		t_nonRecur = clock() - time2;
		//cout << fixed << setprecision(4);
		cout << n[i] << setw(20) << ((float)t_recur) / CLOCKS_PER_SEC << setw(20) << ((float)t_nonRecur) / CLOCKS_PER_SEC << setw(20) << Fibo_value << endl;

		i++;
	}
	
}
//recursive algorithm 
long int FiboR(int n) // array of size n
{
	if (n == 0 || n == 1)
		return (n);
	else return (FiboR(n - 1) + FiboR(n - 2));
}


//non - recursive algorithm 
long int FiboNR(int n) // array of size n
{
	int F[1000];
	F[0] = 0; F[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		F[i] = F[i- 1] + F[i - 2];
	}
	return (F[n]);
}

/*OUTPUT:

Integer     FiboR (seconds)     FiboNR(seconds)          Fibo-value
1                   0                   0                   1
5                   0                   0                   5
10                   0                   0                  55
15                   0                   0                 610
20               0.001                   0                6765
25               0.006                   0               75025
30               0.088                   0              832040
35               0.873                   0             9227465
40               4.629                   0           102334155
45              63.638                   0          1134903170
50             1156.48                   0          -298632863

*/