#include <stdio.h>
#include<stdbool.h>
int result(int a[][4],int n){
    for(int  i = 1 ;i<=n ;i++){
        if(a[i][1]==a[i][2] && a[i][2]==a[i][3]&&a[i][1]!=-1)
        return a[i][1];
    }
    for(int  j = 1 ;j<=n ;j++){
        if(a[1][j]==a[2][j] && a[2][j]==a[3][j]&&a[1][j]!=-1)
        return a[1][j];
    }
    if(a[1][1]==a[2][2] &&  a[2][2]==a[3][3] && a[1][1]!=-1)
    {
        return a[1][1];
    }
    if(a[1][3]==a[2][2] &&  a[2][2]==a[3][1] && a[1][3]!=-1)
    {
        return a[1][3];
    }
    return -1;
}
void print(int a[][4],int n){
      for(int i = 1 ; i<=n ;i++){
        for(int j = 1 ; j<=n ;j++){
            if(a[i][j]==-1)printf(" ");
            if(a[i][j]==1)printf("X");
            if(a[i][j]==2)printf("O");
           // printf("%d",a[i][j]);
            if(j<n)printf("\t|\t");
        }

        printf("\n");
       if(i<n) printf("---------------------------------------");
        printf("\n");

    }
}
int main()
{
    int n=3;
    int a[4][4];
    for(int i = 1 ; i<=n ;i++){
        for(int j = 1 ; j<=n ;j++){
           // if
            a[i][j]=-1;
        }
    }

    bool player1=true;
    bool player2=false;
    while(true){
        print(a,n);

        if(player1){
            int r,c;
            abr:
            printf("player1 trun (X),enter row and colum:");
            scanf("%d%d",&r,&c);
            if(a[r][c]!=-1){
                printf("already fillup . please try again");
                goto abr;
            }
            a[r][c]=1;
            player1=false;
            player2=true;
        }
        else{
             int r,c;
            abr1:
            printf("player2 trun (O),enter row and colum:");
            scanf("%d%d",&r,&c);
            if(a[r][c]!=-1){
                printf("already fillup . please try again");
                goto abr1;
            }
            a[r][c]=2;
            player2=false;
            player1=true;


        }
        if(result(a,n)==1){
                printf("\n");
                 printf("\n");
            printf("----------player1 won!!!------------\n");
            print(a,n);
             printf("\n");
              printf("\n");
            break;
        }
        if(result(a,n)==2){
            printf("\n");
            printf("-----------player2 won!!!----------\n");
            print(a,n);
         printf("\n");
          printf("\n");
            break;
        }


    }

    return 0;
}

