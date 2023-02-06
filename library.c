#include <stdio.h>

int currentState=-1; // ++하고 나서 여기 넣을 차례.
int arrStack[10];
int thisAmount=10;

void printStack(void){
    int j=0;
    for(j=0;j<thisAmount;j++){ //print test
        if(arrStack[j]!=NULL){ //null값은 표시 안해.
            printf("%3d,", arrStack[j]);
        }
    }
    printf("\n");
}
void compareInput(int inputData){
    int i,j,temp=0;
    for(i=0;i<10;i++){//같은값은 안넣을거야
        if(inputData==arrStack[i])
            return;
    }
        switch (currentState) {
            case -1:
                currentState++;
                arrStack[currentState] = inputData;
                break;

            case 0 : //첫번째 값만 있는 경우.
                currentState++;
                if(arrStack[0]>inputData){
                    arrStack[1]=arrStack[0];
                    arrStack[0] = inputData;
                } else{
                    arrStack[1]=inputData;
                }
                break;

            case 9: // 꽉 차있는 경우.
                printf("스택이 꽉 차있습니다 \n");
            break;

           default : //일반적인 경우.
           currentState++;// 여기 의심해보기

               for(i=0;i<(currentState-1);i++){ //아무리 반복해도 currentState-1 (위에서 1개 더했고 )
                   if(arrStack[i]>inputData){
                       temp = i;
                   }
               }
               for(j=0;j<(currentState-temp);j++){//뒤로 밀기.
                  arrStack[currentState+1-j]=arrStack[currentState-j];
               }

               arrStack[temp] = inputData;
                break;
    }
}

int main(void) {
     //10번 입력
    int inputData,onOff=1;
    int i,j  = 0;

    int tempIndex = 0;
    int menu=0;
    for (i = 0; i < thisAmount; i++) { //init
        arrStack[i] = 0;
    }
    while (menu>=0) {
        switch(menu){
            case 1:
                printf("input your num: \n");
                scanf("%d", &inputData);
                compareInput(inputData);
                menu = 0;
                break;
            case 3:
                printStack();//print
                menu = 0;
                break;
            case 4:
                menu = -1;
                break;
            default:
                printf("select menu ( 1.input 2.none 3.print 4. exit )\n");
                scanf("%d", &menu);
        }
    }

//new feature
    return 0;
}