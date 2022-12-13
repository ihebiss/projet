#include <stdio.h>
#include "function.h"

void taux (char * filename,float *te,float *tn)
{
    int nbr_obs=0;
    int nbr_obst=0;
    int nbr_obse=0;
    utilisateur L;
    FILE * f=fopen(filename,"r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %s %d %d %d %d %d %s %s\n",L.nom,L.prenom,&L.d.j,&L.d.m,&L.d.a,L.cin,&L.role,&L.genre,&L.num_bureau_vote,&L.vote,&L.nationalite,L.profess,L.appartenance_politique)!=EOF)
        {
            if (L.role==3)
            {
                nbr_obs++;
            if (L.nationalite==1){
                   nbr_obst++;
            }
            if (L.nationalite==2)
            {
                nbr_obse++;
            }
            }
        }
        *te=(float)nbr_obse/nbr_obs;
        *tn=(float)nbr_obst/nbr_obs;

        }
    fclose(f);
}

