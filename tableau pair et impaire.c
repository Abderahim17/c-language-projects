#include <stdio.h>
#include <stdlib.h>


const K = 100;

void main(){

int T[K];
int N,V,TEST;
printf("Donner la taille de tableau : ");
scanf("%d",&N);
for (int i = 0 ; i < N ; i++){
    printf("\n Donner un nombre : ");
    scanf("%d",&T[i]);
}

for (int i = 0 ; i < N ; i++){
    printf("  %d  ", T[i]);
}

printf("\n Donner un valeur : ");
scanf("%d",&V);

TEST = 0;

for (int i = 0 ; i < N ; i++){
    if (T[i] == V){
        TEST = 1;
    }
}
if ( TEST == 1){
    for (int i = 0 ; i < N ; i++){
    if (T[i]%V==0 && V <= 100){
    printf("  %d  ", T[i]);
    }
}
}


int temp;
int cpt = 0;
for (int i = 0 ; i < N ; i++){
    if (T[i] == V){
        temp = i+1;
        cpt++;
    }
}

if (cpt == 0){
    printf("not existed");
}
else{
    printf("\n last position of %d  is  : %d  ", V,temp);
}


}

