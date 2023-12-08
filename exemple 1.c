#include <stdio.h>
#include <stdlib.h>

typedef struct ElementListe{
int Val;
struct ElementListe * Suiv;
}Liste;

void InsererDebut (Liste *L , int X)
{
    Liste *P = malloc(sizeof(Liste));
    P->Val = X ;
    P->Suiv = L ;
    L = P ;
}
void InsererFin (Liste *L , int X)
{
    if (L == NULL){
        InsererDebut(&L , X);
    }
    else
    {

    Liste *Current = L;
    while(Current->Suiv != NULL){
        Current = Current->Suiv ;
    }
    Liste *P = malloc(sizeof(Liste));
    P->Val = X ;
    P->Suiv = NULL ;
    Current->Suiv = P;
    }
}

void SupprimerDebut (Liste *L)
{
    if(L == NULL){
        printf("liste vide");
    }
    else{
        Liste *P = L;
        L = L->Suiv;
        free(P);
    }
}

void SupprimerFin (Liste *L)
{
    if(L == NULL){
        printf("liste vide");
    }
    else{
        if((L)->Suiv == NULL){
            SupprimerDebut (&L);
        }
        else{
          Liste *Current = L;
          while((Current->Suiv)->Suiv != NULL){
          Current = Current->Suiv ;
          }
          Current->Suiv = NULL;
        }
    }
}

int Longueur(Liste *L)
{
    int NBR=0;
    if(L == NULL){
        return (NBR);
    }
    else{
       while(L != NULL){
            L = L->Suiv;
            NBR++;
       }
    }
    return (NBR);
}

int Somme(Liste *L)
{
    int S=0;
    if(L == NULL){
        return (S);
    }
    else{
       while(L != NULL){
            S = S + (L->Val);
            L = L->Suiv;
       }
    }
    return (S);
}

void Affichage (Liste *L)
{
   if(L == NULL){
        printf("liste vide");
    }
    else{
       while(L != NULL){
         printf("%d  ->" , L->Val);
         L = L->Suiv;
       }
       printf(" NULL");
    }
}





void main()
{

 int N,V,i;

 Liste *Lpair = NULL;
 Liste *Limpair = NULL;

 printf("donner la taille de liste :");
 scanf("%d",&N);
 for(i=0 ; i<N ; i++)
 {
    printf("donner un element :");
    scanf("%d",&V);
    if (V%2==0){
        InsererDebut(&Lpair,V);
    }
    else{
        InsererFin(&Limpair,V);
    }
 }
printf("\n");
Affichage(&Lpair);
printf("\n");
Affichage(&Limpair);
printf("\n La longueur de Lpair  :  %d", Longueur(Lpair));
printf("\n La longueur de Limpair  :  %d", Longueur(Limpair));
printf("\n La Somme de Lpair  :  %d", Somme(Lpair));
printf("\n La Somme de Limpair  :  %d", Somme(Limpair));
SupprimerDebut(&Lpair);
SupprimerDebut(&Limpair);
SupprimerFin(&Lpair);
SupprimerFin(&Limpair);
printf("\n \n");
Affichage(Lpair);
printf("\n \n");
Affichage(Limpair);
printf("\n La longueur de Lpair  :  %d", Longueur(Lpair));
printf("\n La longueur de Limpair  :  %d", Longueur(Limpair));
printf("\n La Somme de Lpair  :  %d", Somme(Lpair));
printf("\n La Somme de Limpair  :  %d", Somme(Limpair));
}

