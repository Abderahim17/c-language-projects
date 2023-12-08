#include <stdio.h>
#include <stdlib.h>
typedef struct Element Element;
struct Element
{
    int val;
    Element *suiv;
};
typedef Element* List;

void InsererDebut(int x , List *L);
void afficherList(List L);
void InsererFin(int x , List *L);
int Longueur(List L);
int Somme(List L);
void SupprimierPremier(List *L);
void SupprimierDernier(List *L);

int main(){





    //initilisation des lists
   /* List Lpair = NULL;
    List Limpair = NULL;*/
    List L = NULL;
    InsererDebut(12,&L);
    InsererDebut(120,&L);
    InsererDebut(55,&L);
   // printf("\n          INSERTION A LA FIN             \n\n");
    InsererFin(18,&L); //insertion a la fin
    InsererFin(12,&L);
    InsererFin(0,&L);
    InsererFin(44,&L);
    afficherList(L); //affichage de la liste

    printf("\n             LONGUEUR DE LISTE              \n");
    //affichage de longueur de la liste
    printf("Le Longueur de la list est : %d ",Longueur(L));
    printf("\n           SUPREMIER PREMIER DE LISTE          \n\n");
    SupprimierPremier(&L);
    //affichage de la liste
    afficherList(L);InsererDebut(12,&L);

    printf("\n           SUPREMIER DERNIER DE LISTE             \n\n");
    SupprimierDernier(&L);
    //affichage de la liste
    afficherList(L);
InsererDebut(12,&L);
    printf("\n          LA SOMME DES ELEMENTS DE LISTE           \n");
InsererDebut(12,&L);
    printf("La somme des elements de la liste egal a : %d\n",Somme(L));InsererDebut(12,&L);




    return 0;
}
void InsererDebut(int x , List *L){
    List p = malloc(sizeof(List)); //Reserve element a memoire
    p->val=x;
    p->suiv=*L;
    *L = p;
}

void InsererFin(int x , List *L){
List p=malloc(sizeof(List));

    if(*L==NULL){
        InsererDebut(x,L);
    }else{
        List ptr = *L;
        while (ptr->suiv != NULL)
        {
            ptr = ptr -> suiv;
        }
        p->val = x;
        p->suiv = NULL;
        ptr->suiv = p;

}
}

void afficherList(List L){
    //si la liste est vide on afficher se msg..
    if(L == NULL) {
        printf("La L est vide");
    }else{
        List p; //Declaration De List Assistante
        p=L;
        while(p != NULL){

            printf("%d-->",p->val);
            p=p->suiv;
        }
        printf("NULL");


    }
}

int Longueur(List L){
    List p ;
    p=L; //list asistance
    int longueur=0;
    if(L != NULL){
        while(p!=NULL){
           longueur++;
            p=p->suiv;
        }
    }

    return longueur;
}

int Somme(List L){
    List p ;
    p=L; //list asistance
    int somme=0;
    if(L != NULL){
        while(p!=NULL){
             somme = somme + p->val;
             p=p->suiv;
        }
    }

    return somme;
}

void SupprimierPremier(List *L){
    if(*L!= NULL){
        List p;
        p=*L;
        *L=(*L)->suiv;
        p->suiv = NULL;
        free(p);
    }
}

void SupprimierDernier(List *L){
    if(*L != NULL) {

        //si la list n est pas null and suiv est null
        if((*L)->suiv == NULL) {
        *L = NULL;
        } else {

        List p = *L; //liste assistance
        while(p->suiv->suiv != NULL)
            p = p->suiv;

        List lastelement = p->suiv;
        p->suiv = NULL;
        free(lastelement);
        }
  }
}
