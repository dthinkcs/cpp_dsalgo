// Change in the given string itself. So no need to return or print anything

void removeX(char input[]) {
  if(input[0]=='\0')
    return;
  if(input[0] != 'x')
    removeX(input+1);
  else
  {
    // shift by one
    int i=1;
    for(;input[i - 1]!='\0';i++)
    {
      input[i-1]=input[i];
    }
    
    removeX(input);
  }	
}
