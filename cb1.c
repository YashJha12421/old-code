#include <stdio.h>
#include <string.h>
#include<math.h>
int main() {
    int o;
    scanf("%d", &o);
    printf("n");
    for (int i = 0; i < o; i++) {
        int n;
        scanf("%d", &n);
        int m;
        scanf("%d", &m);
        int mtrx[n][m];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d", &mtrx[i][j]);
            }
        }
        
        int c=0;
        for(int k=0; (k<n/2)&&(k<m/2) ;k++){
            int array[3001];
            int y=0;
            for(int r=k; r<m-k;r++){
                array[y]=mtrx[k][r];
                y++;
            }
            for(int r=k;r<n-k;r++){
                array[y]=mtrx[r][m-k-1];
                y++;
            }
            for(int r=m-k-1;r>=k;r--){
                array[y]=mtrx[n-k-1][r];
                y++;
            }
            for(int r=n-k-1;r>=k;r--){
                array[y++]=mtrx[r][k];
            }
            array[y++]=mtrx[k][k+1];
            array[y++]=mtrx[k][k+2];

            
            for(int p=0;p<y-3;p++){
                if(array[p]==1 && array[p+1]==5 && array[p+2]==4 && array[p+3]==3){
                    c++;
                }
            }
            printf("g");

        }
        printf("%d\n", c);

    }
    return 0;
}
