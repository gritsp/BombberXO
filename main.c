#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

char TABLE[9][9][10];
char P1[10] = "XX";
char P2[10] = "OO";

void clrscr(){
    system("@cls||clear");
}

void initial(int Size){

    int i,j,n;
    char pos[10];
    for (i=0;i<Size;i++){
        for (j=0;j<Size;j++){
            n = (i+1)*10+j+1;
            sprintf(pos,"%d",n);
            strcpy(TABLE[i][j],pos);
        }
    }
}

int checkPositon(int Pos){
    int i,j;
    i = Pos/10-1;
    j = Pos%10-1;

    if (strcmp(TABLE[i][j],P1) == 0 || strcmp(TABLE[i][j],P2) == 0){
        return 1;
    }
    return 0;
}

void choosePosition(int Pos,int Player){
    int i,j;
    i = Pos/10-1;
    j = Pos%10-1;
    if (Player == 1){
        strcpy(TABLE[i][j],P1);
    }
    else
    {
        strcpy(TABLE[i][j],P2);
    }
    
}

int chckWiner(int Size, int Player){
    int i;    
    for (i=0;i<=Size;i++){
        int j;
        for (j=0;j<=Size;j++){
            if (Size == 9){
                if (Player == 1){
                    if (strcmp(TABLE[i][j],P1) == 0 && strcmp(TABLE[i+1][j-1],P1) == 0 && strcmp(TABLE[i+2][j-2],P1) == 0 &&
                        strcmp(TABLE[i+3][j-3],P1) == 0 && strcmp(TABLE[i+4][j-4],P1) == 0){
                            return 1;
                    }
                    if (strcmp(TABLE[i][j],P1) == 0 && strcmp(TABLE[i][j+1],P1) == 0 && strcmp(TABLE[i][j+2],P1) == 0 &&
                        strcmp(TABLE[i][j+3],P1) == 0 && strcmp(TABLE[i][j+4],P1) == 0){
                            return 1;
                    }
                    if (strcmp(TABLE[i][j],P1) == 0 && strcmp(TABLE[i+1][j],P1) == 0 && strcmp(TABLE[i+2][j],P1) == 0 &&
                        strcmp(TABLE[i+3][j],P1) == 0 && strcmp(TABLE[i+4][j],P1) == 0){
                            return 1;
                    }
                    if (strcmp(TABLE[i][j],P1) == 0 && strcmp(TABLE[i+1][j+1],P1) == 0 && strcmp(TABLE[i+2][j+2],P1) == 0 &&
                        strcmp(TABLE[i+3][j+3],P1) == 0 && strcmp(TABLE[i+4][j+4],P1) == 0){
                            return 1;
                    }
                    
                }
                if (Player == 2){
                    if (strcmp(TABLE[i][j],P2) == 0 && strcmp(TABLE[i][j+1],P2) == 0 && strcmp(TABLE[i][j+2],P2) == 0 &&
                        strcmp(TABLE[i][j+3],P2) == 0 && strcmp(TABLE[i][j+4],P2) == 0){
                            return 2;
                    }
                    if (strcmp(TABLE[i][j],P2) == 0 && strcmp(TABLE[i+1][j],P2) == 0 && strcmp(TABLE[i+2][j],P2) == 0 &&
                        strcmp(TABLE[i+3][j],P2) == 0 && strcmp(TABLE[i+4][j],P2) == 0){
                            return 2;
                    }
                    if (strcmp(TABLE[i][j],P2) == 0 && strcmp(TABLE[i+1][j+1],P2) == 0 && strcmp(TABLE[i+2][j+2],P2) == 0 &&
                        strcmp(TABLE[i+3][j+3],P2) == 0 && strcmp(TABLE[i+4][j+4],P2) == 0){
                            return 2;
                    }
                    if (strcmp(TABLE[i][j],P2) == 0 && strcmp(TABLE[i+1][j-1],P2) == 0 && strcmp(TABLE[i+2][j-2],P2) == 0 &&
                        strcmp(TABLE[i+3][j-3],P2) == 0 && strcmp(TABLE[i+4][j-4],P2) == 0){
                            return 2;
                    }
                }
            }
            else
            {
                if (Player == 1){
                if (strcmp(TABLE[i][j],P1) == 0 && strcmp(TABLE[i+1][j-1],P1) == 0 && strcmp(TABLE[i+2][j-2],P1) == 0 &&
                    strcmp(TABLE[i+3][j-3],P1) == 0 ){
                        return 1;
                }
                if (strcmp(TABLE[i][j],P1) == 0 && strcmp(TABLE[i][j+1],P1) == 0 && strcmp(TABLE[i][j+2],P1) == 0 &&
                    strcmp(TABLE[i][j+3],P1) == 0 ){
                        return 1;
                }
                if (strcmp(TABLE[i][j],P1) == 0 && strcmp(TABLE[i+1][j],P1) == 0 && strcmp(TABLE[i+2][j],P1) == 0 &&
                    strcmp(TABLE[i+3][j],P1) == 0 ){
                        return 1;
                }
                if (strcmp(TABLE[i][j],P1) == 0 && strcmp(TABLE[i+1][j+1],P1) == 0 && strcmp(TABLE[i+2][j+2],P1) == 0 &&
                    strcmp(TABLE[i+3][j+3],P1) == 0 ){
                        return 1;
                }
                
            }
            if (Player == 2){
                if (strcmp(TABLE[i][j],P2) == 0 && strcmp(TABLE[i][j+1],P2) == 0 && strcmp(TABLE[i][j+2],P2) == 0 &&
                    strcmp(TABLE[i][j+3],P2) == 0 ){
                        return 2;
                }
                if (strcmp(TABLE[i][j],P2) == 0 && strcmp(TABLE[i+1][j],P2) == 0 && strcmp(TABLE[i+2][j],P2) == 0 &&
                    strcmp(TABLE[i+3][j],P2) == 0 ){
                        return 2;
                }
                if (strcmp(TABLE[i][j],P2) == 0 && strcmp(TABLE[i+1][j+1],P2) == 0 && strcmp(TABLE[i+2][j+2],P2) == 0 &&
                    strcmp(TABLE[i+3][j+3],P2) == 0 ){
                        return 2;
                }
                if (strcmp(TABLE[i][j],P2) == 0 && strcmp(TABLE[i+1][j-1],P2) == 0 && strcmp(TABLE[i+2][j-2],P2) == 0 &&
                    strcmp(TABLE[i+3][j-3],P2) == 0 ){
                        return 2;
                }
            }
            }
            
            
        }
    }
    return 0;
}

void draw(int Size){
    clrscr();
    int i,j;
    char pos;
    for (i=0;i<Size;i++){
        for (j=0;j<Size;j++){
            printf("| %s ",TABLE[i][j]);
        }
        printf("|\n");
    }
}

int main(){
    initial(9);
    
    int Pos,Size;
    int Player =1;
    printf("Input Size\n");
    printf("1. 7*7\n2. 9*9\n");
    scanf("%d",&Size);
    while (Size != 1 && Size != 2)
    {
        printf("Please input Size\n");
        printf("1. 7*7\n2. 9*9\n");
        scanf("%d",&Size);
        //Size = 1;
    }
    
    
    while (1)
    {   
        if(Size == 1){
            Size = 7;
        }
        else
        {
            Size = 9;
        }
          
        draw(Size);
        printf("Input position\n>");
        scanf("%d",&Pos);
        while (checkPositon(Pos) == 1) 
        {
            printf("Please Input position\n>");
            scanf("%d",&Pos);
        }             
     
        choosePosition(Pos,Player);
        draw(Size);
        if(chckWiner(Size,Player) != 0){
            if(chckWiner(Size,Player) == 1){
                printf("Player1");
                break;
            }
            else
            {
                printf("Player 2");
                break;
            }
            
        }
        // Player +=1;
        // if (Player>2){
        //     Player =1;
        // }
    }
    
    return 0;
}