#include <stdio.h>
#include <stdlib.h>

int asciiCount(char *a){
    int b =0;
    b =(int)(*a)/65;
    return b;
}
struct scannedStruct {
   int length;
   int firstIndex;
};
int main(void) {
    //int (*p)[5] = mprmpr;
    // p = (int(*)[5]);
    //int (*p)[5] = (int(*)[5])mprmpr; //(int)는 형변환. [5] 배열단위 설정

    /*int count = 1;
    for (int i = 0; i <5 ; i++) {
        for (int j = 0; j < 5; j++) {
            //(p[i]+j) = count++;
            *(p[i][j]) = count++;
            printf("%3d", *(p[i][j]));
        }
        printf("\n");
    }*/

    // #문자열 5개를 입력받아 문자의 개수가 가장 긴 문자열부터 작은 문자열 순으로 나열하여 출력. 문자열 문자개수 20개.

    //char (*p)[5] = (char(*))malloc(sizeof(char)*100 );//우리가 하고싶은 형태.

    //말록 배열형 테스트

    //char (*p)[5] = (char(*)[20])malloc(sizeof(char)*100 ); //도대체이건 왜 안되냐?

    //int (*pii)[5][20] = (int(*))malloc(sizeof(int)*100 );           // 이건 틀린 코드 x
    //int (*pii) = (int(*)[5][20])malloc(sizeof(int)*100 );          //이건 틀린 코드 x 맨 앞 괄호 빼도 마찬가지.
    //int (*p)[0] = (int(*)[5][20])malloc(sizeof(int)*100 );    // 이건 올바른 코드o
    //int (*p)[5] = (int(*)[20])malloc(sizeof(int)*100 );           // 이건 올바른 코드o
    struct scannedStruct pStruct[5];
    struct scannedStruct temp;
    char p[5][20];
    int i,j,count = 0;
    int countArr[5]={0,0,0,0,0};
    //init
    for(i=0;i<5;i++){
        for(j=0;j<20;j++){
            p[i][j]= NULL;
        }
    }
    for(i=0;i<5;i++){
        printf("input room number %d, 20char: ", i);
        scanf("%20s", &p[i]);//20개로 제한하는 코드 추가해줘. 나머지는 '\0' 으로 채우기.
        printf("%s \n", p[i]);
        pStruct[i].firstIndex=i;
    }
    printf("\n");
    //아스키 코드로 더해주기.
    for(i=0;i<5;i++){
        for(j=0;j<20;j++){
           count = count + asciiCount(&(p[i][j]) );
        }
        pStruct[i].length = count;
        //countArr[i]=count;
        count =0;
        //printf("\n%d", pStruct[i].length);//체크용
    }
   // t j i
    //큰 순서대로 countArr을 바꿔주기.
    int tempNum = 0;
        for(i=0;i<5;i++){
            temp=pStruct[i];
            for(j=i; j<5;j++){
                if(temp.length < pStruct[j].length) {
                    temp = (pStruct[j]);
                    tempNum= j;
                    }
                }
            if((pStruct[tempNum].length!=pStruct[i].length) && i!=4) { //마지막에도 바꿔버리네 미친년 마지막 5는 빼준다.
                pStruct[tempNum] = pStruct[i];
                pStruct[i] = temp;
            }
        }

    //print

    printf("\n순서는\n");
        for(i=0;i<5;i++){
            printf("길이: %2d, 방 넘버%d번 \n",pStruct[i].length, pStruct[i].firstIndex);//구조체 전체를복사하기 때문에 처음 값도 복사된다.
        }

    //printf("\n%d", '\0');
    //2302040120 added
    return 0;
}
