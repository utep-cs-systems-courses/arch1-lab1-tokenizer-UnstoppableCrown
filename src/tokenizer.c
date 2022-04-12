#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
  //  printf("\nspace_char works");
  if(c == ' ' || c == '\t')
    {
      return 1;
    }
  return 0;
  
}

int non_space_char(char c)
{
  // printf("\nnonspace char works");
  if(c != ' ' && c != '\t' && c != '\0')
    {
      return 1;
    }
  return 0;
}

char *word_start(char *str)
{
  //printf("\nword start works");
  for(int i = 0; *(str + 1) != '\0'; i++)
    {
      if(non_space_char(*(str + i)))
	{
	  return str + i;
	}
    }
  return 0;
}
  
 char *word_terminator(char *word)
 {
   //printf("\nword terminator works");
   int i;
   for(i = 0; *(word + i) != '\0'; i++)
     {
       if(space_char(*(word + i)))
	 {
	   return word + i;
	 }
     }
   //printf("\n%s", word);
   return word + i;
 }

 int count_words(char *str)
 {
   //printf("\ncount words works");
   int count = 0;
   int i = 0;
   while(str)
     {
       str = word_start(str);
       if(str)
	 {
	   count++;
	   str = word_terminator(str);
	 }
     }
   
   //printf("\n%d",count);
   return count;
 }

 char *copy_str(char *inStr, short len)
 {
   //printf("\ncopy str works");
   int i = 0;
   char *outStr = malloc((len+1) * sizeof(char));

   while(i <= len)
     {
       outStr[i] = inStr[i];
       i++;
     }
   outStr[i] = '\0';
   return outStr;
 }

char **tokenize(char *str)
{
  //printf("\ntokenize starts");
  int word_count = count_words(str);
  char **tokens = (char**)malloc(sizeof(char*) * (word_count + 1));

  char* terminator = str;
  for(int i = 0; i < word_count; i++)
    {
      str = word_start(terminator);
      terminator = word_terminator(str);
      //printf("\n%d word count", word_count);
      tokens[i] = copy_str(str, terminator-str);
      
      //printf("%d tokenizer terminator %d", i, word_count);
    }

  // char **terminator = tokens + word_count;
  tokens[word_count] = '\0';
  // *terminator = 0;
  //printf("\ntokenize finished");
  return tokens;
}
 void print_tokens(char **tokens)
 {
   //printf("\nprint tokens works");
   int i;
   for(i = 0;tokens[i]; i++)
     {
       //printf("\nStart of while in print");
       printf("\n%s", tokens[i]);  
       //printf("\n %d checking i\n", i);
     }
   
   //printf("\n %d", i);
   // printf("\n", *tokens);
   //printf("end of print");
 }

 void free_tokens(char **tokens)
 {
   int i;
   for(i = 0;tokens[i]; i++)
     {
       free((tokens[i]));
     }
     free(tokens);
 }

