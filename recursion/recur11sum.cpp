int sum(int input[], int n) {
	if(n==0) {
  		return 0;
	}
  	return input[0] + sum(input+1,n-1); 

}

int sum2(int input[], int n)
{
	if (n == 0)
      return 0;
  return input[n - 1] + sum(input, n - 1);
}
