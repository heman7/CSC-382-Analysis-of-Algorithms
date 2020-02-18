//Heman Zhang
//CSC382
//Professor Petingi
//Project 5
//3/29/2018
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

int B[200050];
void Fixheap(int A[], int root, int key, int bound);
void Heapsort(int A[], int n);
void Mergesort(int A[], int low, int high);
int Insertion(int A[], int);
void Merge(int A[], int low, int mid, int high);
int sequence2[200050];
int sequence3[200050];
int main()
{
	srand(time(NULL));
	clock_t time, time2, time3, t_insertion, t_merge, t_heap;
	int n[] = { 100, 1000, 10000, 50000, 100000, 200000 };
	int bound = 10000;
	int sequence[200050];
	cout << left << setw(17) << "Input Size" << setw(35) << "Insertion Sort(time in seconds)" << setw(35) 
		<< "Merge Sort(time in seconds)" << setw(35)<<"Heap Sort(time in seconds)" << endl;

	for (int i = 0; i < 6; i++)
	{


		for (int k = 0; k < n[i]; k++)
		{
			sequence[k] = rand() % bound;
			sequence2[k] = sequence[k];
			sequence3[k] = sequence[k];
		}
		time = clock();

		Insertion(sequence, n[i]);
		t_insertion = clock() - time;

		time2 = clock();
		Mergesort(sequence2, 0, n[i] - 1);
		t_merge = clock() - time2;

		time3 = clock();
		Heapsort(sequence3, n[i]);
		t_heap = clock() - time3;




		cout << setprecision(3) << fixed;

		cout << left << setw(17) << n[i] << setw(35) << ((float)t_insertion) / CLOCKS_PER_SEC << setw(35) 
			<< ((float)t_merge) / CLOCKS_PER_SEC << setw(35)<< ((float)t_heap)/CLOCKS_PER_SEC   << endl;

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

void Mergesort(int A[], int low, int high)
{

	if (low < high) { // if the sub-list has more than one element
		int mid = (low + high) / 2;
		Mergesort(A, low, mid); // we call Mergesort for the first half
		Mergesort(A, mid + 1, high);// we call Mergesort for the second half
		// at this point the two halves are sorted
		Merge(A, low, mid, high);
	}
} // end algorithm

void Heapsort(int A[], int n)
		  {
			  int i, heapsize, max;

			  // *******  Heap Construction *******//
			  for (i = (n / 2); i >= 1; i--)
				  Fixheap(A,i, A[i], n);

			  // ******* Heap Sort **************//

			  for (heapsize = n; heapsize >= 2; heapsize--)
			  {
				  max = A[1]; // max is the largest key
				  Fixheap(A,1, A[heapsize], heapsize - 1);
				  A[heapsize] = max;
			  }

		 }

void Fixheap(int A[], int root, int key, int bound)
// key is the key to be placed at the root, and
// bound is index of the rightmost node of the last level 

{
	int vacant, Lgrchild; //Lgrchild is the child with the largest key of the vacant node 
	bool inserted = false;  // if we can not re-arrange a heap any further we
	// set inserted = true.

	vacant = root; // originally, the vacant node is the root 
	while ((2 * vacant <= bound) && (!inserted))
	{
		Lgrchild = 2 * vacant; /* we make the right child be the node with largest key */
		if ((Lgrchild < bound) && A[Lgrchild + 1] > A[Lgrchild]) // if vacant node has
			// right child and
			// right child has the 
			// largest key.
			Lgrchild++;
		if (key <  A[Lgrchild])
		{
			A[vacant] = A[Lgrchild];
			vacant = Lgrchild;
		}
		else inserted = true;
	}
	A[vacant] = key;
}

/*OUTPUT
Input Size       Insertion Sort(time in seconds)    Merge Sort(time in seconds)        Heap Sort(time in seconds)
100              0.00                               0.00                               0.00
1000             0.00                               0.00                               0.00
10000            0.17                               0.00                               0.00
50000            4.95                               0.01                               0.01
100000           8.76                               0.02                               0.02
200000           36.55                              0.05                               0.04
Press any key to continue . . .

Input Size       Insertion Sort(time in seconds)    Merge Sort(time in seconds)        Heap Sort(time in seconds)
100              0.000                              0.000                              0.000
1000             0.001                              0.000                              0.000
10000            0.122                              0.003                              0.001
50000            4.849                              0.019                              0.013
100000           9.024                              0.020                              0.021
200000           35.845                             0.040                              0.041
Press any key to continue . . .*/