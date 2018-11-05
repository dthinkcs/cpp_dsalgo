// input: 6
// output: 1 2 3 4 5 6
void print(int n){
    if(n == 1){
        cout << n << " ";
    }
  	else
    {
      print(n - 1);
      cout << n << " ";
    }
}
