// 1234
// 123
// 12 



// 1
// 12
// 123 
// 1234 
// 123
// 12 
// 1
/*
void print(int n){
    if(n < 10){
    	cout << n << endl;
    }
  	else
    {
        print(n / 10); 
     	cout << n << endl;
    	print(n / 10); 
    
    	// after IHOP => realize NOT THE SAME SUBPROBLEM
    }
}
*/

void grow(int n)
{
  if (n < 10)
    cout << n << endl;
  else
  {
    grow(n / 10);
    cout << n << endl;
  }
}

void shrink(int n)
{
  if (n < 10)
    cout << n << endl;
  else
  {
    cout << n << endl;
    shrink(n / 10);
    
  }
}

void print(int n)
{
  if (n < 10)
    cout << n << endl;
  else
  {
    grow(n / 10);
    cout << n << endl;
    shrink(n / 10);
  }
  
}
