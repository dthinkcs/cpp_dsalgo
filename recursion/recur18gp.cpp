double geometricSum(int k) {
    // Write your code here
if(k==0){
  return 1;
}
  return geometricSum(k-1) + 1/pow(2,k);
}
