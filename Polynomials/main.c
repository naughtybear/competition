#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d, before = 0, done = 1, tmp, i, j;
    int in[3], array[2][30] = {0};
    //while(scanf("%d%d%d%d", &in[2], &in[1], &in[0], &d)!=EOF){
    scanf("%d%d%d%d", &in[2], &in[1], &in[0], &d);
    array[before][0] = 1;
    while(d--)
    {
        for(i = 0; i < 30; i++)
            array[done][i] = 0;
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 30; j++)
            {
                array[done][i + j] += array[before][j] * in[i];
            }
        }
        tmp = before;
        before = done;
        done = tmp;
    }
    for(i = 29; i > 0; i--)
    {
        if(array[before][i] != 0)
            break;
            //printf("%d ", array[before][i]);
           // printf("%d ",i);
    }
    do{
        //printf("%d ",i);
        printf("%d", array[before][i]);
        if(i!=0)
            printf(" ");
    }while(i--);
    printf("\n");
    //if(array[before][0]!=0)printf("%d\n", array[before][0]);
    //else printf("\n");
    //}
    return 0;
}
