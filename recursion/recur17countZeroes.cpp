
int countZeros(int n) {
    // Write your code here
/*if(n <=9){
  if(n==0){
    return 1;
  }
  else{
    return 0;
  }
}
  int last =n%10;
  int count = 0;
  if(last ==0){
    count =1;
  }
  return count + countZeros(n/10)*/
  if(n == 0)
    return 0;
 
  if(n % 10 == 0)
    return 1 + countZeros(n / 10);
  else 
  	return countZeros(n / 10);		
 
}
