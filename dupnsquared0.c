#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main() {
  char* s =  get_string();
  
  
  char words[10][10];
  int j = 0, k = 0, space_before = true;
  for (int i = 0, len = strlen(s); i < len; i++)
  {
    if (space_before)
    {
      if (s[i] != ' ')
      {
        space_before = false;
        words[j][k++] = s[i]; 
      }
    }
    else 
    {
      if (s[i] != ' ')
        words[j][k++] = s[i];
      else
      {
        space_before = true;
        words[j][k] = '\0';
        k = 0;
        j++;
      }
    }
    
  }
  if (!space_before)
    words[j][k] = '\0';
    
    
  // removing duplicates  
  for (int i = 0; i < 10; i++)
  {
    char* word = words[i];
    for (int j = i + 1; j < 10; j++)
      if (strcmp(word, words[j]) == 0)
        words[j][0] = '\0';
    
  }
  
  // printing without the duplicates
  for (int i = 0; i < 10; i++)
  {
    if (strcmp(words[i], "") != 0)
      printf("%s ", words[i]);
  }
  
}
