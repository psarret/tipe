#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>

typedef struct node
{
  int id;
  char type;/*type : 
	      e = éolien -> prod variable
	      n = nucléaire -> prod fixe
	      b = barrage -> prod adaptative
	      c = consommateur
	    */
  
  double debit; /*positif si c'est une source, negatif si c'est un consomateur*/
  struct node * voisins[5];
  
}node;

node * create_node(int id, char type, double debit)
{
  if(type == 'c'){assert(debit < 0);}
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
      printf("production insuffisante pour consommateur %d\n",conso->id);
    }
   
  if(source->debit + conso->debit > 0)
    {
      source->debit += conso->debit;
      adj[source->id-1][conso->id-1] = 1;
      adj[conso->id-1][source->id-1] = 1;
    }
}


/*fonction pour la fluctuation */



void var_conso_prod(node element)
{
  assert(element.type != 'n');
  
  if(element.type == 'c')
    {
      /*variation pour le consommateur*/
    }

  if(element.type == 'e')
    {
      /*variation pour l'eolien */
    }

  if(element.type == 'b')
    {
      /*variation pour le barage*/
    }
}



void print_mat_adj(int ajd[5][5])
{
  for(int i=0; i<5; i++)
    {
      for(int j=0; j<5; j++)
	{
	  printf("%d",ajd[i][j]);
	}
      printf("\n");
    }
}

void test ()
{
  for(int i=0; i<100; i++)
    {
      system("clear");
      printf("test %d",i);
      fflush(stdout);
      sleep(1);
    }
}

int main()
{
  srand(time(NULL));
  
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
    
    
    mettre tout les noeuds dans une liste 
    integrer une gestion de la consommation en fonction de l'heure ? (plus de consommation à certain horaires)
    gérer la resistance des lignes 
  */
  
  
  node * source1 = create_node(1,'n',10.0);
  node * source2 = create_node(2,'n',10.0);
  node * consomateur3 = create_node(3,'c',-3.0);
  node * consomateur4 = create_node(4,'c',-2.0);
  node * consomateur5 = create_node(5,'c',-1.0);
  
  set_power_line(source1,consomateur3,mat_adj);
  set_power_line(source2,consomateur4,mat_adj);
  set_power_line(source1,consomateur3,mat_adj);
  set_power_line(source1,consomateur4,mat_adj);
  set_power_line(source1,consomateur5,mat_adj);
  
  printf("débit source : %f\n",source1->debit);
  print_mat_adj(mat_adj);
  test();
  /*

system("clear") 
getchar()
*/
  
  return 0;
}
