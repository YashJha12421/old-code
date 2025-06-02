#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){
    if (a>b){
        return a;
    }
    return b;
}

typedef struct node{
    int val;
    struct node *next;
    struct node *prev;
} Node;

int main(){
    struct node *Head = malloc(sizeof(Node));
    int m=0;
    struct node *temp = malloc(sizeof(Node));
    int n=0;
    Head=NULL;
    temp=NULL;
    while(1){
        struct node *node1 = malloc(sizeof(Node));
        
        scanf("%d", &m);
        if(m==-1){

            break;
        }
        n++;
        node1->val=m;
        
        if (Head==NULL){
            Head=node1;
            temp=Head;
            Head->prev=NULL;
            
            continue;
        }
        temp->next=node1;
        temp->next->prev=temp;
        temp=temp->next;

        node1->next=NULL;
    }

    //ghj
    temp=Head;
    while(temp->next!=NULL){
        printf("%d ", temp->val);
        
        temp=temp->next;

    }
    printf("%d\n", temp->val);
    
    
    for(int i=0;temp!=NULL;temp=temp->prev){
        printf("%d ", temp->val);
        i++;

    }

    int r;
    scanf("%d", &r);
    temp=Head;
    int m1=max(r-1, n-r);
    int diff;
    if(r-1>n-r){
        diff=2*r-n-1;
    }
    else{
        diff=n+1-2*r;
    }
    struct node*nde=Head;
    for(int i=0;i<m1-1;i++){
        nde=nde->next;
    }
    struct node*nde2=nde;
    for(int i=m1;i<m1+diff-1;i++){
        nde2=nde2->next;
    }
    nde->prev->next=nde2;
    nde->next->prev=nde2;
    nde2->next->prev=nde;
    nde2->prev->next=nde;






    //ghjk
    int k;
    temp=Head;
    scanf("%d", &k);
    for(int i=0;i<k-1;i++){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;


    temp=Head;
    while(temp->next!=NULL){
        printf("%d ", temp->val);
        
        temp=temp->next;

    }
    printf("%d\n", temp->val);
    
    
    for(int i=0;temp!=NULL;temp=temp->prev){
        printf("%d ", temp->val);
        i++;

    }
    printf("\n");
    //dfg
    
    struct node*temp2=Head;

    while(temp2->next!=NULL){
        
        if(temp2->val==temp2->next->val){
            temp2->next=temp2->next->next;
            if (temp2->next==NULL){
                break;
            }
            temp2->next->prev=temp2;
            continue;
        }
        
        
        temp2=temp2->next;

    }
    struct node*temp1=Head;

    while(temp1->next!=NULL){
        printf("%d ", temp1->val);
        
        temp1=temp1->next;

    }
    printf("%d\n", temp1->val);



    


    return 1;
}