#include <stdio.h>
#include <stdlib.h>

const k=1000;

void LireTab (int N, int *T){
int i;
for (i=0;i<N;i++){

    printf("donner un nomber : ");
    scanf("%d",&T[i]);
}
}

int MaxTab (int N, int *T){
int max=T[0];
for (int i=1;i<N;i++){
    if (T[i]>max){
        max = T[i];
    }
}
return max;
}


int NbrOccMax (int N, int *T){
int max = MaxTab(N,T);
int cpt = 0;
for (int i=0;i<N;i++){
    if (T[i]==max){
        cpt++;
    }
}
return cpt;
}


void AfficherTab (int N, int *T){
for (int i=0;i<N;i++){
    printf("%d  ",T[i]);
}
}



int main()
{
    int N;
    int T[k];
    printf("donner la taille\n");
    scanf("%d",&N);
    LireTab(N,T);
    printf(" le max : %d\n",MaxTab(N,T));
    printf("nbr occ : %d\n",NbrOccMax(N,T));
    AfficherTab (N,T);
    return 0;
}
