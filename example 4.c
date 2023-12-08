#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int v;
    struct element * suiv;
}liste;

liste *ajouterliste(liste *L,int val)
{
   liste *nouveau, *par;
    nouveau=(liste *)malloc(sizeof(liste));
     nouveau->v=val;
      nouveau->suiv=NULL;
       if (L==NULL){
         L=nouveau;
       }
        else{
            par=L;
             while(par->suiv != NULL){
                    par=par->suiv;
             }
             par->suiv=nouveau;
        }

    return L;

}
liste *InsererDebut(liste *L , int val)
{
    liste * b;
     b=(liste *)malloc(sizeof(liste));
      b->v=val;
       b->suiv=L;
        L=b;
        return L;

}
 liste *InsererFIN(liste *L , int val)
{
    liste *b , *par;
     b=(liste *)malloc(sizeof(liste));
      b->v=val;
       b->suiv=NULL;
        if (L==NULL)
            {
          L=b;
            }
          else
             {
           par=L;
            while (par->suiv != NULL)
               {
             par=par->suiv;
               }
              par->suiv=b;
               }
               return L;

}
 void SuprimerPremier(liste **L)
 {
     liste *b;
      if (*L!= NULL)
      {
          b=*L;
          *L=(*L)->suiv;
          free(b);
      }

 }
 void SuprimerFin(liste **L)
 {
      liste *par;
      if (*L!=NULL)
      {
          if ((*L)->suiv == NULL)
          {
              free(*L);
              *L=NULL;

          }
           else
           {
               par=*L;
                while (par->suiv->suiv != NULL)
                {
                    par = par->suiv;
                }
                free(par->suiv);
                par->suiv=NULL;
           }
      }

 }
  void AfficherListe(liste *L)
{
    liste *par;
     par=L;
      if (L==NULL)
        {
       printf("la liste est vide");
        }
        else
            {
         while(par != NULL)
                {
          printf("%d||",par->v);
           par=par->suiv;
                }
            }
}

 int longueur(liste *L)
 {
     int cpt;
      cpt=0;
       liste *par;
        par=L;
    if (par == NULL)
      {
          printf("la liste vide");
      }
       else
       {
           while(par != NULL)
           {
               cpt=cpt+1;
               par=par->suiv;
          }
       }
       return cpt;
  }
int SommeElemns(liste * L)
{
    int some;
    some=0;
    if (L==NULL)
        return some;

    else
    {
        while(L!=NULL)
        {


        some=some+L->v;
        L=L->suiv;
        }
    }
    return some;
}

int main()
{
    liste *l1=NULL;
    liste *lpaire=NULL;
    liste *limpaire=NULL;
    liste *p;
    int n , i , nbr;
    printf("\nDonner moi nomber des elemts :");
    scanf("%d",&nbr);
      for (i=1;i<=nbr;i++)
      {
          printf("Valeur Number %d:",i);
          scanf("%d",&n);
         l1= ajouterliste(l1,n);
      }
        p=l1;
           while (p!= NULL)
           {
               if(p->v % 2==0){
                    lpaire=InsererFIN(lpaire,p->v);
               }
                else{
                    limpaire=InsererDebut(limpaire,p->v);
                }
                p=p->suiv;
           }
         printf("\nTaille de List Piar: %d\n",longueur(lpaire));
         printf("\nTaille de List imPiare: %d\n",longueur(limpaire));
         printf("\nLa Somme des elemnts est: %d\n",SommeElemns(l1));
         printf("\nles element de la liste pair est:\n");
         AfficherListe(lpaire);
         printf("\n\nles element de la liste impair est:\n");
         AfficherListe(limpaire);
         SuprimerFin(&lpaire);
         SuprimerFin(&limpaire);
         SuprimerPremier(&lpaire);
         SuprimerPremier(&limpaire);
         getch();
         printf("\nsuppression liste pair\n");
         AfficherListe(lpaire);
         printf("\nsuppression liste impair \n");
         AfficherListe(limpaire);
         getch();
         printf("\nTaille de List Piar: %d\n",longueur(lpaire));
         printf("\nTaille de List imPiare: %d\n\n",longueur(limpaire));
    return 0;
}
