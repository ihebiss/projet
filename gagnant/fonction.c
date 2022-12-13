#include <stdio.h>
#include "fonction.h"
int cond_gagn()
{
utilisateur L;
int r[100];
int z=0;
int n=0;
FILE *f;
FILE *f1;
f= fopen("utilisateur.txt","a+");
 while(fscanf(f,"%s %s %d %d %d %s %d %d %d %d %d %s %s\n",L.nom,L.prenom,&L.d.j,&L.d.m,&L.d.a,L.cin,&L.role,&L.genre,&L.num_bureau_vote,&L.vote,&L.nationalite,L.profess,L.appartenance_politique)!=EOF)
{
r[z]=L.vote;
z++;
}
int maxcount = 0;
    int gagnant;
   int i,j,c;
for(i=0;i<z-1;i++){
    for(j=i+1;j<z;j++)
        if ( r[i] < r[j] ) {
            c = r[i];
            r[i] = r[j];
            r[j] = c;
        }
}
f1= fopen("vote.txt","w+");
 for (int i = 0; i < z; i++) {
     fprintf(f1,"%d \n" , r[i]);
printf("%s" ," ");
        }
return gagnant;
}









