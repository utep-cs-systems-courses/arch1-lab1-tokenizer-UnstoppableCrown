#include "tokenizer.h"
#include <stdio.h>
#include "history.h"
#include <stdlib.h>

int main()
{
  char input[100];
  List *history = init_history();
  while(1)
    {
      printf("\nTo quit enter 'q' To type a sentence type 't' To check a specific spot in the history type '!' followed by which entry in history To check all history type 'h'");
      fputs(">", stdout);
      fgets(input, 100, stdin);

      if(input[0] == 'q')
	{
	  goto done;
	}
      else if(input[0] == 't')
	{
	  printf("Type your sentence here \n>");
	  fflush(stdin);
	  fgets(input, 100, stdin);
	  //printf("right before tokenize");
	  char** tokens = tokenize(input);
	  print_tokens(tokens);
	  add_history(history, input);
	  free_tokens(tokens);
	}
      else if(input[0] == '!')
	{
	  char *hist = get_history(history,atoi(input+1));
	  char **tokens = tokenize(hist);
	  printf("Retrieved history: %s\n", hist);
	  printf("Tokenized history: \n");
	  print_tokens(tokens);
	  free_tokens(tokens);
      }
      else if(input[0] == 'h')
	{
	  print_history(history);
	}
    }
 done:// end command
  return 0;
}

