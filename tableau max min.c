#include <stdio.h>
#include <stdlib.h>


 void liretab (int n , int tab[]){
 int i ;


for(i=0;i<n;i++){
     printf("DONNER UNE NOMBRE SVP:\t");
  scanf("%d",&tab[i]);
}
 }

 int tabmax (int n ,int tab[]){

 int i ;

 int max =tab[0];

 for(i=1;i<n;i++){


 if (tab[i]>max ){
    max =tab[i];
 }
 }return max ;
 }
  int NBrOccMax (int n ,int tab[]){
 int i, cpt ,m ;

   m = tabmax (n,tab ) ;
    cpt = 0 ;
 for(i=0;i<n;i++){

 if (m==tab[i]){

    cpt++ ;
 }
 }
  return cpt;
  }
 void AfficherTab(int n, int tab[]){
 int i ;
 for (i=0;i<n;i++){
    printf ("         %d",tab[i]);
 }
 }
int main()
{
    int tab[125],n ;
    printf(" TAPER UNE NOMBRE SVP:\t");
    scanf("%d",&n);
    liretab (n,tab);
    printf("\n Le MAX ET %d", tabmax(n,tab));
    printf("\n LE NOMBRE DE OCCERENCE ET %d", NBrOccMax(n,tab));
    printf("\n");
    AfficherTab(n,tab);

    return 0;
}
