#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int id;
  char type;/*type : 
	      e = éolien
	      n = nucléaire
	      ...
	    */
  
  double debit; /*positif si c'est une source, negatif si c'est un consomateur*/
  struct node * voisins[5];
  
}node;

node * create_node(int id, char type, double debit)
{
  node * node = malloc(sizeof(node));
  node->id = id;
  node->type = type;
  node->debit = debit;

  return node;
}

void set_power_line(node * source, node * conso, int adj[5][5])
{
  if(source->debit + conso->debit <= 0)
    {
      printf("production insuffisante\n");
    }
   
  if(source->debit + conso->debit > 0)
    {
      source->debit += conso->debit;
      adj[source->id][conso->id] = 1;
      adj[conso->id][source->id] = 1;
    }
}


int main()
{
  int mat_adj [5][5] =
    {
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
    };
  /*
  node source = {1,'n',10.0};
  node consomateur = {2,'c',-1.0};
  */
  node * source = create_node(1,'n',10.0);
  node * consomateur = create_node(2,'c',-1.0);

  set_power_line(source,consomateur,mat_adj);

  printf("débit source : %f\n",source->debit);
  
  return 0;
}
