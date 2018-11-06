int sumOfDigits(int n) {
   if(n <= 9){
     return n;
   } 
  return n % 10 + sumOfDigits(n / 10);

}


int sumOfDigits(int n) {
   if(n == 0)
     return 0;
  
  return n % 10 + sumOfDigits(n / 10);

}


