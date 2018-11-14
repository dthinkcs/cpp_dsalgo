#include <iostream>
using namespace std;

void merge(int arr[], int lStart, int lEnd, int rStart, int rEnd)
{
  int A[rEnd - rStart + 1 + lEnd - lStart + 1];
  int i1 = lStart, i2 = rStart;
  int k = 0;
  while (i1 <= lEnd && i2 <= rEnd)
  {
    if (arr[i1] < arr[i2])
      A[k++] = arr[i1++];
    else
      A[k++] = arr[i2++];
  }

  while (i1 <= lEnd)
    A[k++] = arr[i1++];

  while (i2 <= rEnd)
    A[k++] = arr[i2++];

  i1 = lStart, i2 = rStart;
  for (int i = 0; i < k; i++)
  {
    if (i1 <= lEnd)
      arr[i1++] = A[i];
    else
      arr[i2++] = A[i];
  }
}

void mergeSortH(int arr[], int start, int end)
{
  if (start >= end)
    return;

  int mid = (start + end) /2;
  mergeSortH(arr, start, mid);
  mergeSortH(arr, mid + 1, end);
  merge(arr, start, mid, mid + 1, end);
}

void mergeSort(int arr[], int n)
{
  mergeSortH(arr, 0, n - 1);
}

int main()
{
  int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  mergeSort(arr, 10);

  for (int i = 0; i < 10; i++)
    cout << arr[i] << endl;

}
