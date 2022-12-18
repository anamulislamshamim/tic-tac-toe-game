#include<stdio.h>
#include<stdbool.h>
void ui(int matrix[][3], int n, int m)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(matrix[i][j]==-1)printf("\t \t");
            if(matrix[i][j]==1)printf("\tX\t");
            if(matrix[i][j]==2)printf("\t0\t");
            if(j<n-1)printf("\t|\t");
        };
        if(i<n-1)printf("\n________________________________________________________________________________");
        printf("\n\n");
    };
};

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
    bool player1=true;
    bool player2=false;
    while(true){
        ui(matrix, n, m);
        if(player1){
            int r,c;
            printf("Player 1 Turn (X). Enter the Row and Column. The value will be (0-2): ");
            scanf("%d%d",&r,&c);
            matrix[r][c]=2;
            player1=false;
            player2=true;
        }else{
            int r,c;
            printf("Player 2 Turn (0). Enter the Row and Column. The value will be (0-2): ");
            scanf("%d%d",&r,&c);
            matrix[r][c]=1;
            player1=true;
            player2=false;
        }
    }
    ui(matrix, n, m);
    return 0;
}