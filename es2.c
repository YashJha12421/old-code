#include<stdio.h>
#include<string.h>
int main(){
    int n, m=0;
    int k=1;
    int i=0;
    scanf("%d\n", &n);
    char string[n];
    for(m=0;m<n;m++){
        scanf("%c", &string[m]);
    };
    for(i=0;i<n;i++){
        if (string[i]==string[n-i-1]){
            continue;
        }
        else{
            k=0;
        };
    };
    if(k==1){
        printf("yes");
    
    }
    else{
        printf("no");
    };
    return 0;


}
