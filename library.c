#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int i=0;
    char *pchar[5];
   for(i=0;i<5;i++){
       pchar[i] = (char*)malloc(sizeof(char)*20 );
       printf("input \n");
       scanf("%s", *&(pchar[i]) );
       printf("%s\n", *&(pchar[i]) );

   }


/*
    printf("input your num: \n" );
    scanf("%d", &inputData);
    int arrState =0;


    {//넣을때 지금까지 넣은값들 비교해서, 뒤에 값이랑 비교하기, 뒤의 숫자들 밀고, 그다음 넣기.
        if(arrState!=10){

        }
    }*/

    return 0;
}