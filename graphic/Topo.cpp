#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include<iostream>
#include <stdlib.h>
struct node
 {
    int dinh_ke;
    struct node *next;
 };
typedef struct node *NODEPTR;
struct   phantu_ke
{
   int count;
   NODEPTR pF;
   NODEPTR pL  ;
};
typedef struct phantu_ke  Dothi[100];
Dothi G;
int MAX;
void Init_graph(Dothi G)
{
   for(int i=0; i< MAX; G[i++].pF=NULL);
}
void Create_graph()
{
 int i,j ;
 NODEPTR p;
 unsigned B[100][100];
 FILE *fptr;
 if ( (fptr = fopen ("dt.txt", "rt")) == NULL )
 {  printf("\nKhong the mo file dt.txt");
    getch();
    exit(0);
 }
 fscanf(fptr,"%d", &MAX);
 for (i=0; i< MAX ; i++)
   for (j=0; j<MAX; j++)
     fscanf(fptr,"%d", &B[i][j]);
  /// Khoi tao rong do thi
  Init_graph(G);
  //Tao count : so cung toi dinh j
  for (j=0; j<MAX; j++)
  {
    G[j].count=0;
    for (i=0; i< MAX; i++)
      if (B[i][j] ==1)  G[j].count++;
  }
  for (i=0; i< MAX; i++)
    for (j=0;j<MAX; j++)
      if (B[i][j] == 1)
      {
p = new node;
p->next=NULL;
p->dinh_ke=j;
if( G[i].pF == NULL)  G[i].pF=p;
else G[i].pL->next=p;
G[i].pL=p;
      }
}
void Topo_Sort(Dothi G)
{
  int Stack[100];
  int i,j,k, Sp=-1 ;
  NODEPTR  p;
  for(i=0;i<MAX; i++)  // Dua vao Stack tat cac cac nut khong co cung di 
	// toi no
    if (G[i].count==0)  {  // day la cac task co the lam doc lap
			      Stack[++ Sp]=i;
			 }
  for( i=0; i<MAX; i++)
  {
    if (Sp ==-1)
    {
       printf("\nCo chu trinh trong do thi!!!");
       exit(0);
    }
    j=Stack[Sp--];  printf("%5d",j);  // Lay 1 nut trong Stack ra
    p=G[j].pF;
    while (p !=NULL)
    {
      k=p->dinh_ke; // k la ngon cua cung j --> k
      G[k].count --;
      if (G[k].count == 0)  // khong co dinh nao toi nut k
      {
	  Stack[++Sp]=k;
      }
      p=p->next;
    }
  }
}
int main()
{  //clrscr();
   Create_graph();
   Topo_Sort(G);
   getch();
}
