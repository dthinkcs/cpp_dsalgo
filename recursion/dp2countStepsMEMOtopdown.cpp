
#include <climits> 
int countStepsTo1H(int n, int* ans){

  if (n <= 1)
    return 0;

  if (ans[n] != -1)
    return ans[n];
  
  int x = countStepsTo1H(n - 1, ans);
  int y;
  int z;
  if (n % 2 == 0)
  	y = countStepsTo1H(n / 2, ans);
  else
    y = INT_MAX;

  if (n % 3 == 0)
  	z = countStepsTo1H(n / 3, ans);
  else
    z = INT_MAX;
  
  ans[n] = 1 + min(x, min(y, z));
  return ans[n];
}

int countStepsTo1(int n)
{
  int ans[n + 1]; // 0 to n
  for (int i = 0; i <= n; i++)
    ans[i] = -1;
    
  return countStepsTo1H(n, ans);
}

