#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"



List *init_history()
{
  List *list = malloc(sizeof(List));
  list->root= malloc(sizeof(Item));
  return list;
}

void add_history(List *list, char *str)
{
  int id = 1;
  Item *temp = list->root;
  while(temp->next != 0)
    {
      temp = temp->next;
      id++;
    }
  temp->next= malloc(sizeof(Item));
  int i;
  for (i = 0; str[i] != '\0'; ++i);
  temp->next->str = copy_str(str, i);
  temp->next->id = id;
}

char *get_history(List *list, int id)
{
  Item *item = list->root;
  while(item != 0)
    {
      if(item->id == id)
	{
	  return item->str;
	}
      item = item->next;
    }
}

void print_history(List *list)
{
  Item *temp = list->root->next;
  while(temp != 0)
    {
      printf("%d. %s", temp->id, temp->str);
      temp = temp->next;
    }
}

void free_history(List *list)
{
  Item *current = list->root;
  while(current->next!= 0)
    {
      Item *previous = current;
      current = current->next;
      free(previous->str);
      free(previous);
    }
  free(current->str);
  free(current);
  free(list);
}
