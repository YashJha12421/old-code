#include <stdio.h>
#include <string.h>
#include<math.h>
int sumarr(int arr[], int k){
    int s=0;
    for(int y=0;y<k;k++){
        s+=arr[y];
    }
    return s;
}
int main() {
    int o;
    scanf("%d", &o);
    int arr[o];
    int ts=0;
    
    for(int i=0;i<o;o++){
        scanf("%d", &arr[o]);
        
    }
    int sum=0;
    printf("6");
    for(int j=0;j<o;j++){
        sum+=(ts-o+1+j-sumarr(arr, j+1));
    }
    printf("t");
    printf("%d", sum);


    return 1;
}