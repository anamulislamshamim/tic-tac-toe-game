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

// check who is win
/*

0   x   0
x   0   x
0   x   0

*/
int whoIsWin(int matrix[][3], int n)
{

    int i,j;
    for(i=0;i<n;i++){
        if(matrix[i][0] == matrix[i][1] && matrix[i][1]  == matrix[i][2] && matrix[i][0] != -1){
            return matrix[i][0];
        };
    };
    for(j=0;j<n;j++){
        if(matrix[0][j]==matrix[1][j] && matrix[1][j] == matrix[2][j] && matrix[0][j] != -1){
            return matrix[0][j];
        };
    };
    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0]!=-1){
        return matrix[0][0];
    };
    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[1][1] != -1){
        return matrix[1][1];
    };

    return -1;

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
    // take user input:
    while(true){
        ui(matrix, n, m);
        if(player1){
            int r,c;
            Flag1:
            printf("Player 1 Turn (X). Enter the Row and Column. The value will be (0-2): ");
            scanf("%d%d",&r,&c);
            if(matrix[r][c] != -1){
                printf("Invalid Cell\n");
                goto Flag1;
            }
            matrix[r][c]=2; 
            player1=false;
            player2=true;
        }else{
            int r,c;
            Flag2:
            printf("Player 2 Turn (0). Enter the Row and Column. The value will be (0-2): ");
            scanf("%d%d",&r,&c);
            if(matrix[r][c]!=-1){
                printf("Invalid Cell\n");
                goto Flag2;
            }
            matrix[r][c]=1;
            player1=true;
            player2=false;
        };
        // check who is win
        if(whoIsWin(matrix, n) == 1){
            printf("\n\nPlayer 1 is won!\n\n");
            break;
        }else if(whoIsWin(matrix, n) == 2){
            printf("\n\nPlayer 2 is won!\n\n");
            break;
        }
    };   
    ui(matrix, n, m);
    return 0;
}