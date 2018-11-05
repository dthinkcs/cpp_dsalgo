// INPUT n: 1234
// 1234
// 123
// 12 
// 1
// 12
// 123 
// 1234 

void print(int n){
    if(n < 10){
    	cout << n << endl;
    }
  	else
    {
     	cout << n << endl;
    	print(n / 10); 
    	cout << n << endl;
    }
}
