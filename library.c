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



    return 0;
}