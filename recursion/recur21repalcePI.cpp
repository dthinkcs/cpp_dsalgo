// Change in the given string itself. So no need to return or print anything
int length(char* input)
{
  if(input[0]=='\0')
    return 0;
  return length(input+1)+1;
}



void shift(char* input)
{
  int len = length(input);
  int i = len;
  for(;i>=0;i--){
    input[i+2]=input[i];
  }
 
  return;
}
  
  
void replacePi(char input[]) {
	// Write your code here
  if(input[0]=='\0')
	return;
  if(input[0]=='p' && input[1]=='i'){

    
    input[0]='3';
    input[1]='.';
    shift(input+2);
    input[2]='1';input[3]='4';
    replacePi(input+4);
  }
  else
  {
    replacePi(input+1);
  }
    
  
  
}


