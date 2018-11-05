// figuring out all the base cases
// one way is to draw out a Recursion Tree example
// ...then maybe mathematically prove the base cases work
// AND THAT THERE ARE SUFFICIENT BASE CASES for the recursion to stop
// more DeliberateP: is the problem(buggyness/mudiness) in Recursion or the Math

// n with parts of size at most m
int countPartitions(int n, int m)
{
  if (n == 0)
    return 1;
  if (n < 0 || m == 0)
    return 0;
  // with_m and with_out_m
  return countPartitions(n - m, m) + countPartitions(n, m - 1);
}
