#include <stdio.h>
#include <stdlib.h>

typedef struct nature
{
  char type;
  int debit;
  
}nature;


typedef struct consomateur
{
  int conso;
  
}consomateur;


typedef struct node
{
  nature nature;
  node * tab;
  
}node;

int main()
{
  return 0;
}
