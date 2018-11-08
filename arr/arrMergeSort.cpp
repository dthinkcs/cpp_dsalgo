void merge(int input[], int start,int end)
{
  int* arr = new int[end - start + 1]; int k = 0;
  int mid = (start + end ) / 2; 
  int i1 = start;
  int i2 = mid + 1;
  while (i1 <= mid && i2 <= end)
  {
    if (input[i1] <= input[i2])
      arr[k++] = input[i1++];
    else
      arr[k++] = input[i2++];
  }
  
  while (i1 <= mid)
  	arr[k++] = input[i1++];
    
  while (i2 <= end)
    arr[k++] = input[i2++];
  
  // copy into input
  
  for (int i = 0; i < k; i++)
    input[start++] = arr[i];
}

void merge(int input[], int start,int end)
{
  int* arr = new int[end - start + 1]; int k = 0;
  int mid = (start + end ) / 2; 
  int i1 = start;
  int i2 = mid + 1;
  while (i1 <= mid && i2 <= end)
  {
    if (input[i1] <= input[i2])
      arr[k++] = input[i1++];
    else
      arr[k++] = input[i2++];
  }
  
  while (i1 <= mid)
  	arr[k++] = input[i1++];
    
  while (i2 <= end)
    arr[k++] = input[i2++];
  
  // copy into input
  k = 0;
  for (int i = start; i <= end; i++)
    input[i] = arr[k++];
}
void merge(int input[], int start,int end)
{
  int* arr = new int[end - start + 1]; int k = 0;
  int mid = (start + end ) / 2; 
  int i1 = start;
  int i2 = mid + 1;
  while (i1 <= mid && i2 <= end)
  {
    if (input[i1] <= input[i2])
      arr[k++] = input[i1++];
    else
      arr[k++] = input[i2++];
  }
  
  while (i1 <= mid)
  	arr[k++] = input[i1++];
    
  while (i2 <= end)
    arr[k++] = input[i2++];
  
  // copy into input
  int idx = 0;
  for (int i = start; i <= end; i++)
    input[i] = arr[idx++];
}



void mergeSortHelper(int input[], int start, int end)
{
  if(start>=end)
    return;
  int mid = (start+end)/2;
  mergeSortHelper(input, start, mid);
  mergeSortHelper(input, mid+1,end);
  merge(input,start,end);
}

void mergeSort(int input[], int size){
	// Write your code here
        mergeSortHelper(input, 0 , size-1);
}
