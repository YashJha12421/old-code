#include<stdio.h>
int main(){
    struct storage{
        char name[20];
        int roll_no;
        int a;
        int b;
        int c;
    };
    int i,k,j;
    for(i=0;i!=-6;i++){
        struct storage alp[i];
        int q;
        printf("Enter 1 for entering info, 0 for displaying everything and stopping: ");
        scanf("%d\n", &q);
        if (q==0){
            for(j=0;j<i;j++){
                for(k=0;j<20;j++){
                    printf("%c", alp[j].name[k]);
                };
                printf("%d", alp[j].roll_no);
                printf("%d", alp[j].a);
                printf("%d", alp[j].b);
                printf("%d", alp[j].c);
        
            };
            break;
        };
        for(k=0;j<20;j++){
            if(alp[i].name[k-1]==' '){
                alp[i].name[k]=' ';
                continue;
            }; 
            scanf("%c", &alp[i].name[k]);
        };
        scanf("%d", &alp[i].roll_no);
        scanf("%d", &alp[i].a);
        scanf("%d", &alp[i].b);
        scanf("%d", &alp[i].c);
    };
    
    
    return 0;
    





}