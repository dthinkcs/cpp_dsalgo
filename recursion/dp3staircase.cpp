long staircaseH(int n, long* ans){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
    if (n <= 1)
      return 1;
  	if (n == 2)
      return 2;
  	if (n == 3)
      return 4;

  
  	if (ans[n] != -1)
      return ans[n];
  
  	ans[n] = staircaseH(n - 1, ans) + staircaseH(n - 2,ans) + staircaseH(n - 3, ans);
  	return ans[n];
}



long staircase(int n){
  
  long ans[n + 1];
  for (int i = 0; i <= n; i++)
    ans[i] = -1;
  return staircaseH(n, ans);
}
