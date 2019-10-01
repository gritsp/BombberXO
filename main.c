#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

char TABLE[9][9][10];
char P1[10] = "XX";
char P2[10] = "OO";
int Bomb[9][9][10];
char B[10] = "BB";
char H[10] = "HH";

int ScoreP1;
int ScoreP2;

void clrscr(){
    system("@cls||clear");
}

void initial(int Size){
    ScoreP1 = 100;
    ScoreP2 =100;
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

int checkWiner(int Size, int Player){
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
    printf("Score Player 1: %d\n",ScoreP1);
    printf("Score Player 2: %d\n",ScoreP2);
    for (i=0;i<Size;i++){
        for (j=0;j<Size;j++){
            printf("| %s ",TABLE[i][j]);
        }
        printf("|\n");
    }
}

void BombRandom(int Size){
    int i,row,col;
    if(Size == 7){
        srand(time(NULL));
        for(i=0;i<3;i++){
            row = rand()%7;
            col = rand()%7;
            strcpy(Bomb[col][row],B);
            //strcpy(TABLE[col][row],B);
        }
        for (i = 0; i < 2; i++)
        {
            row = rand()%7;
            col = rand()%7;
            strcpy(Bomb[col][row],H);
            //strcpy(TABLE[col][row],B);
        }
        
        
    }
    else
    {
        srand(time(NULL));
        for(i=0;i<4;i++){
            n = rand()%81;
            Bomb[n] = 'B';
        }
        for (i = 0; i < 3; i++)
        {
            n = rand()%81;
            Bomb[n] = 'H';
        }
    }
    
}

int checkBomb(int Pos, int Player){
    int i,j;
    i = Pos/10-1;
    j = Pos%10-1;
    if(Player ==1){
        if(Bomb[i][j]=='B'){
            ScoreP1 -=50;
            strcpy(TABLE[i][j],H);
        }
        if(Bomb[i][j]=='H'){
            if(ScoreP1<100){
                ScoreP1 += 50;
                strcpy(TABLE[i][j],H);
            }
        }
        if(ScoreP1 <= 0){
            return 2;
        }
    }
    else if(Player == 2){
        if(Bomb[i][j]=='B'){
            ScoreP2 -=50;
        }
        if(Bomb[i][j]=='H'){
            if(ScoreP2<100){
                ScoreP2 += 50;
            }
        }
        else if(ScoreP2 <=0)
        {
            return 1;
        }
    }
    
    
    return 0;
    

    
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
    if(Size == 1){
        Size = 7;
    }
    else
    {
        Size = 9;
    }
    BombRandom(Size);
    while (1)
    {   
       
          
        draw(Size);
        printf("Input position\n>");
        scanf("%d",&Pos);
        while (checkPositon(Pos) == 1) 
        {
            printf("Please Input position\n>");
            scanf("%d",&Pos);
        }             
     
        choosePosition(Pos,Player);
        checkBomb(Size,Player);
        if(checkBomb(Size,Player) != 0){
            if (checkBomb(Size,Player) == 1){
                printf("Player 1");
            }
            else{
                printf("Player 2");
            }
        }
        draw(Size);
        // if(checkWiner(Size,Player) != 0){
        //     if(checkWiner(Size,Player) == 1){
        //         printf("Player1");
        //         break;
        //     }
        //     else
        //     {
        //         printf("Player 2");
        //         break;
        //     }
            
        // }
        // Player +=1;
        // if (Player>2){
        //     Player =1;
        // }
    }
    
    return 0;
}