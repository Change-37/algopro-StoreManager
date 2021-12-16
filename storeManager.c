#include <stdio.h>

int market[500] = {};
int count;


typedef struct node{
    char data[10] = {};
    char code[20] = {};
}NODE;

void Quick(int list[], int left, int right){

}

void QuSort(int list[], int start, int end){

}

int Bisearch(int list[], int start, int end, int key){
    int mid;
    if(start <= end){
        mid = start + end;
        mid /= 2;
        if(key == list[mid]){
            printf("상품이 존재합니다.");
            return mid;
        }
        else if(key < list[mid]) return Bisearch(list, start, mid-1, key);
        else return Bisearch(list, start, mid-1, key);
    }
    printf("상품이 존재하지 않습니다.");
    return -1;
}

void buy(int list[]);
void search(int list[]);
void check(int list[]);

void Manager(int list[]){
    int a;
    printf("원하시는 서비스를 입력해 주세요.\n1: 구매   2: 상품 검색    3: 재고 확인    0: 나가기");
    scanf("%d", &a);
    switch(a){
        case 1:
            buy(list);
            break;

        case 2:
            search(list);
            break;

        case 3:
            check(list);
            break;

        case 0:
            printf("이용해주셔서 감사합니다.");
            break;

        default:
            printf("잘못된 값이 입력되었습니다.");
            Manager(list);

    }
}

void main(){
    Manager(market);
}

void buy(int list[]){

}

void search(int list[]){
    
}

void check(int list[]){

}

