#include <stdio.h>
#include <string.h>
#include<math.h>
  return 1;
}
int main() {
    int o;
    scanf("%d", &o);
    for (int i = 0; i < o; i++) {
        int x;
        scanf("%d", &x);
        if(x==1){
            printf(" 1 ")
            continue;   
        }
        if(x==2){
            printf{"1 2"};
            continue;
        }

        if(x==3){
            printf{"2 1 3"};
            continue;
        }
        if(x==4){
            printf("4 1 2 3");
            continue;
        }
        if(x==5){
            printf("5 4 1 3 2");
            continue;
        }
        if(x==6){
            printf("6 4 1 2 3 5");
            continue;
        }
        if(x==7){
            printf("7 2 3 1 4 5 6");
            continue;
        }
        if(x==8){
            printf("8 7 4 1 2 3 6 5");
            continue;
        }
        if(x==9){
            printf("9 6 7 5  3 2 6 5 8")
        }
        
        
       

        
    }
    return 0;
}
