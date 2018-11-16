
#include <cmath>
#include <climits>

int countStepsTo1(int n){

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     */
  if (n <= 1)
    return 0;
 
  int ans[n + 1];
  ans[0] = 0;
  ans[1] = 0;
  // bottom up
  for (int i = 2; i <= n; i++)
  {
    int x = ans[i - 1];
    
    int y;
    if (i % 2 == 0)
      y = ans[i / 2];
  	else
      y = INT_MAX;
      
    int z;  
    if (i % 3 == 0)
      z = ans[i / 3];
    else
      z = INT_MAX;
      
    ans[i] = 1 + min(x, min(y, z));
  }

  return ans[n];
}
