//Heman Zhang
//CSC382
//Professor Petingi
//Project 4
//3/22/2018
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

int B[200050];

void Mergesort(int A[], int low, int high);
int Insertion(int A[], int);
void Merge(int A[], int low, int mid, int high);
int sequence2[200050];

int main()
{
	srand(time(NULL));
	clock_t time, time2, t_insertion, t_merge;
	int n[] = { 100, 1000, 10000, 50000, 100000 ,200000};
	int bound = 10000;
	int sequence[200050];
	cout << left << setw(20) << "Input Size" << setw(35) << "Insertion Sort(time in seconds)" << setw(35) << "Merge Sort(time in seconds)" << endl;

	for (int i = 0; i < 6; i++)
	{
		

			for (int k = 0; k < n[i]; k++)
			{
				sequence[k] = rand() % bound;
				sequence2[k] = sequence[k];
			}
			time = clock();
			
			Insertion(sequence, n[i]);
			t_insertion = clock() - time;
			
			time2 = clock();
		    Mergesort(sequence2, 0, n[i]-1);
			t_merge = clock() - time2;

		
		cout << setprecision(2) << fixed;
		
		cout << left << setw(20) << n[i] << setw(35) << ((float)t_insertion) / CLOCKS_PER_SEC << setw(35) << ((float)t_merge) / CLOCKS_PER_SEC << endl;
		
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

void Merge(int A[], int low, int mid, int high) // we assume that B is a global                                                                                     // variable
{
	int l = low, i = low, h = mid + 1, k; // i is the index corresponding to array B
	while ((l <= mid) && (h <= high)) { // exactly one of the pointers will reach its limit
		if (A[l] <= A[h]) {
			B[i] = A[l];      // push A[l] to B
			l++;                //increment l
		}
		else {                 // we must A[h] to B
			B[i] = A[h];
			h++;
		}
		i++;
	}  //end while 
	if (l > mid) {  // we pushed the remaining elements starting at A[h]
		for (k = h; k <= high; k++) {
			B[i] = A[k];
			i++;
		} // end for
	}
	else
	{
		for (k = l; k <= mid; k++) // we push remaining elements starting at A[l]
			B[i] = A[k];
		i++;
	}
	 // end else

	// Next we move B[low:high] to A[low:high] 
	for (k = low; k <= high; k++) {
		A[k] = B[k];
	} // end for
} // end algorithm

void Mergesort(int A[],int low, int high)
{

	if (low < high) { // if the sub-list has more than one element
		int mid = (low + high) / 2;
		    Mergesort(A,low, mid); // we call Mergesort for the first half
	        Mergesort(A,mid + 1, high);// we call Mergesort for the second half
			// at this point the two halves are sorted
		    Merge(A, low, mid, high);
	}
} // end algorithm

/*OUTPUT
Input Size          Insertion Sort(time in seconds)    Merge Sort(time in seconds)
100                 0.00                               0.00
1000                0.00                               0.00
10000               0.11                               0.00
50000               4.21                               0.02
100000              12.39                              0.01
200000              34.59                              0.03
Press any key to continue . . .
Input Size          Insertion Sort(time in seconds)    Merge Sort(time in seconds)
100                 0.00                               0.00
1000                0.00                               0.00
10000               0.12                               0.00
50000               3.19                               0.01
100000              9.18                               0.02
200000              34.48                              0.04
Press any key to continue . . .
*/