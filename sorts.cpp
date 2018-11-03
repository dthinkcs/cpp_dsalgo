#include <iostream>
#define MAX 50
using namespace std;
/*
void adjust(int a[], int n)
{
	int c, temp;
	temp = a[p];

}

void heapSort(int a[], int n)
{
	// ASSUME: arr starts from 1
	for (int i = n )
}
*/


void swap (int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void quickSortHelper(int arr[], int left, int right)
{
	if (left < right)
	{
		int i = left; // because we do k++
		int j = right + 1;
 		int pivot = arr[left];

 		do
 		{
 			do
 			{
 				i++;
 			} while (arr[i] < pivot);
 			do
 			{
 				j--;
 			} while (arr[j] > pivot);

 			if (i < j)
 				swap(arr, i, j);
 		} while (i < j);
 		swap(arr, left, j);
 		// j has the pivot now
 		quickSortHelper(arr, left, j - 1);
 		quickSortHelper(arr, j + 1, right);

	}
}

void quickSort(int arr[], int n)
{
	quickSortHelper(arr, 0, n - 1);
}


void merge(int arr[], int start1, int end1, int start2, int end2)
{
	int i = start1;
	int j = start2;
	int A[MAX];
	int k = 0;
	while (i <= end1 && j <= end2)
	{
		if (arr[i] < arr[j])
			A[k++] = arr[i++];
		else
			A[k++] = arr[j++];
	}

	while (i <= end1)
		A[k++] = arr[i++];

	while (j <= end2)
		A[k++] = arr[j++];

	// copy into arr
	/*
	for (int idx = 0, i = start1, j = start2; idx < k; idx++)
	{
		if (i <= end1)
			arr[i++] = A[idx];
		else
			arr[j++] = A[idx];

	}*/
}

void mergeSortHelper(int arr[], int start, int end)
{
	int sizeOfArr = end - start + 1;
	if (sizeOfArr <= 1)
		return;


	mergeSortHelper(arr, start, start + sizeOfArr / 2); // left half
	mergeSortHelper(arr, start + sizeOfArr / 2  + 1, end); // right half
	merge(arr, start, start + sizeOfArr / 2, start + sizeOfArr / 2  + 1, end);
}

void mergeSort(int arr[], int n)
{
	mergeSortHelper(arr, 0, n - 1);
}


int main(void)
{
	// inital arr
	int arr[] = {-999, 9, 8, 7, -2, 3};

    //mergeSort(arr, 6);
	quickSort(arr, 6);
	for (int i = 0; i < 6; i++)
        cout << arr[i] << endl;
	// heapSort(arr, 6);

	// radixSort(arr, 6);
}
