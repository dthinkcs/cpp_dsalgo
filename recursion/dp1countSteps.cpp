
#include <climits>
int countStepsTo1(int n){

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     */
  
  if (n <= 1)
    return 0;

  int x = countStepsTo1(n - 1);
  int y;
  int z;
  if (n % 2 == 0)
  	y = countStepsTo1(n / 2);
  else
    y = INT_MAX;

  if (n % 3 == 0)
  	z = countStepsTo1(n / 3);
  else
    z = INT_MAX;
  
  return 1 + min(x, min(y, z));
  
}

