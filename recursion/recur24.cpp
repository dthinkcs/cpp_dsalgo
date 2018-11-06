// Change in the given string itself. So no need to return or print the changed string.
int length(char input[]){
  if(input[0]=='\0')
    return 0;
  return length(input+1)+1;
}

void shift(char* input)
{
  int len = length(input);
  int i = len;
  for(;i>=0;i--){
    input[i+1]=input[i];
  }
  return;
}


void pairStar(char input[]) {
    // Write your code here
  
  if(input[0]=='\0')
  	return;

  if(input[0]==input[1])
  {
    shift(input);
    input[1]='*';
    pairStar(input+2);
    
  }
  else 
    pairStar(input+1);
  
  	
  
}
