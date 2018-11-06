bool checkNumber(int input[], int size, int x) {
  if(size == 0){
    return false;
  }
 	
 bool small = checkNumber(input+1 , size -1 ,x);
 if(!small)
 {
   return input[0]==x;
 }
else 
  return true;
}

bool checkNumber(int input[], int size, int x) {
  if(size == 0){
    return false;
  }
 	
	if (input[0] == x)
      return true;
  	return checkNumber(input + 1, size - 1, x);
}

bool checkNumber(int input[], int size, int x) {
  if(size == 0){
    return false;
  }
 	
	if (input[size - 1] == x)
      return true;
  	return checkNumber(input, size - 1, x);
}

bool checkNumber(int input[], int size, int x) {
  if(size == 0){
    return false;
  }
 	
	if (checkNumber(input, size - 1, x))
      return true;
  	return input[size - 1] == x;
}

