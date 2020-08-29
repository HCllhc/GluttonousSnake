#include<stdio.h>
#include<stdlib.h>

#define HEAD 1
#define BODY 2
#define WALL 3
#define AREA 0
#define FOOD 4


int place[50][50] = {0};
int FoodNum = 0;

int InitData(int (*place0)[50])
{
    int i, j;

    place0[24][24] = HEAD;      //Creat Head

    for(i = 0; i < 50; i++)
    {
        place0[0][i] = WALL;
        place0[49][i] = WALL;
        place0[i][0] = WALL;
        place0[i][49] = WALL;
    }                           //Creat Wall

    do{
        i = rand() % 47 + 1;
        j = rand() % 47 + 1;
    }while(place0[i][j] != AREA);

    place0[i][j] = FOOD;        //Creat Food
    FoodNum = 1;

    return 1;
}

int PrintDraw(int (*place1)[50])
{
    int i, j;

    for(i = 0; i < 50; i++){
        for(j = 0; j < 50; j++)
        {
            switch(place1[i][j])
            {
                case AREA:
                    printf(" ");
                    break;

                case HEAD:
                    printf("@");
                    break;

                case BODY:
                    printf("#");
                    break;

                case WALL:
                    printf("&");
                    break;

                case FOOD:
                    printf("$");
                    break;

                default:
                    printf("\nERR1, i = %d, j = %d, place[i][j] = %d\n", i, j, place1[i][j]);
                    break;
            }
        }
        printf("\n");
    }

    return 1;
}





int main(void)
{
    InitData(place);
    PrintDraw(place);

    getchar();
    return 0;
}
