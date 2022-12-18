#include<stdio.h>

int main()
{
    int n=3,m=3;
    int matrix[n][m];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            matrix[i][j]= -1;
        };
    };
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(matrix[i][j] != -1) {
                printf("%d",matrix[i][j]);
            }else{
                printf(" ");
            };
            if(j<n-1)printf("\t|\t");
        };
        if(i<n-1)printf("\n__________________________________");
        printf("\n\n");
    };
    return 0;
}