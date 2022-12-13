#ifndef STATT_H_INCLUDED
#define STATT_H_INCLUDED


#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

typedef struct{
 int j;
 int m;
 int a;

}date ;

typedef struct{
char nom[20];
char prenom[20];
date d;
char cin[20];
int role;
int genre;
int num_bureau_vote;
int vote;
int nationalite;
char profess[20];
char appartenance_politique[20];
}utilisateur;


void taux (char * filename,float *te,float *tn);
#endif // FUNCTION_H_INCLUDED
#endif // STATT_H_INCLUDED

