#include<stdio.h>
int main(){
    int n, i;
    scanf("%d", &n);
    char alfa[n];
    for(i=0;i<n;i++){
        scanf(" %c", &alfa[i]);
    };
    char c1, c2;
    scanf(" %c %c", &c1, &c2);
    for(i=0;i<n;i++){
        if(alfa[i]==c1){
            alfa[i]=c2;
        };
    };
    for(i=0;i<n;i++){
        printf("%c", alfa[i]);
    };
    return 0;
}