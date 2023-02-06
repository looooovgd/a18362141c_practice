#include <stdio.h>
#include <stdlib.h>
struct node { //노트 구조체 선언
    int value;
    struct node *nextPointer;
};
struct node nodeHeader = {//헤더는 항상 존재하기에 여기에
        .value = 0
};

struct node* newNode(struct node* lastNodeP, int input){//노드생성함수
    struct node *p;

    p = (struct node *) malloc(16); //p -> node1번
    lastNodeP->nextPointer=p; //header 에는 1번의 주소를 넣어줘요
    p->value=input; //node1은 value=1이에요
    lastNodeP=p; //이제 마지막으로 거쳐온 노드는 1번입니다. 그곳의 주소가 있죠.

    return p;//이거는 이제 마지막으로 생성한노드의 주소가 되겠죵?
}

int main(void) {
    int i,nodeState =0; //nodeState== 현재 노드가 몇개인지. 0번인 헤더는 세지 않고, 그 다음부터 시작한다.
    int menu=10;
    struct node *lastNodeP = &nodeHeader;
    int input;

    while (menu>0){
        switch (menu) {
        case 1: //노드생성
            printf("\ninput your input-number\n");
            scanf("%d",&input);
            lastNodeP = newNode(lastNodeP, input);
            nodeState++;
            menu=10;
            break;
        case 4:
            menu=-1;
            break;
        case 3: //출력
            lastNodeP = &nodeHeader;
            for(i=0;i<(nodeState+1);i++){//header 까지 같이 출력하기 때문에 (노드의 수 +1)을 해줍니다.
                lastNodeP=lastNodeP->nextPointer; //이전노드에서 출력할 노드로 이동.
                printf("%d노드의 값 (0번은헤더): %d \n",i,lastNodeP->value );
            }
            menu=10;
            break;
        default:
            printf("-----menu----- \n1. to create node\n2. none\n3. print all node value.\n4. exit\n");
            scanf("%d", &menu);

            break;
        }
    }

    return 0;
}