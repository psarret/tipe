#include <stdio.h>
#include <stdlib.h>

typedef struct nature
{

  
  char type;/*type : 
	      s = source
	      c = consomateur*/
  
  double debit; /*positif si c'est une source, negatif si c'est un consomateur*/
  
}nature;


typedef struct node
{
  
  nature nature;
  int node_id;
  
}node;




int main()
{
  node * graph = (node*)malloc(2*sizeof(node));
  int * voisin = (int*)malloc(2*sizeof(int));
  node source = {{"s",10.0}, 1};
  node consomateur = {{"c",-1}, 2};
  
  return 0;
}
