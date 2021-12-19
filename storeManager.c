#include <stdio.h>
#include <string.h>


typedef struct node{
    int code;
    int num;
}NODE;

NODE market[500];
int count;

#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))


int quick(NODE list[], int left, int right)
{
    int low, high;
    NODE temp;
    int pivot;
    low = left;
    high = right+1;
    pivot = list[left].code;
    do
    {
        do
        {
            low++;
        }while(list[low].code < pivot);
        do
        {
            high--;
        }while(list[high].code > pivot);

        if(low<high)
        {
            swap(list[low], list[high], temp);
        }
    }while(low<high);
    swap(list[left], list[high], temp);
    return high;
}

void quicksort(NODE list[], int left,int right)
{
    if(left<right)
    {
        int q=quick(list, left, right);
        quicksort(list, left, q-1);
        quicksort(list, q+1, right);
    }
}

int Bisearch(NODE list[], int start, int end, int key){
    int mid;
    if(start <= end){
        mid = start + end;
        mid /= 2;
        if(key == list[mid].code){
            printf("상품이 존재합니다.\n");
            return mid;
        }
        else if(key < list[mid].code) return Bisearch(list, start, mid-1, key);
        else return Bisearch(list, start, mid-1, key);
    }
    printf("상품이 존재하지 않습니다.\n");
    return -1;
}

void buy(NODE list[]);
void search(NODE list[]);
void check(NODE list[]);
void insert(NODE list[], int name);

void Manager(NODE list[]){
    while(1){
        search(list);
    }
}
void start(NODE list[]){
	NODE Cola;
	Cola.code = 1;
	Cola.num = 12;
	list[0] = Cola;
	NODE Soda;
	Soda.code = 5;
	Soda.num = 10;
	list[1] = Soda;
	count = 2;
	
}
void main(){
	start(market);
    Manager(market);
}

void buy(NODE list[], NODE obj){
    
}

void search(NODE list[]){
    int name;
    char ans;
    printf("찾는 물품의 이름을 입력해 주세요. : ");
    scanf("%d", &name);
    int loca = Bisearch(list, 0, count, name);
    if(loca == -1){
        printf("상품의 데이터를 생성하시겠습니까?[y/n] : ");
        scanf("%c", &ans);
        if(ans == 'y' || ans == 'Y'){
            insert(list, name);
        }
        return;
    }
    printf("물품이 %d번째 칸에 있습니다.\n", loca + 1);
    printf("물품을 구매하시겠습니까?[y/n]\n");
    scnaf("%c", &ans);
    if(ans == 'y' || ans == 'Y'){
        buy(list, list[loca]);
    }
}

void check(NODE list[]){

}

void insert(NODE list[], int name){
    NODE newNode;
    newNode.code = name;
    int amo;
    printf("물품의 수량을 입력해 주세요. : ");
    scanf("%d", &amo);
    newNode.num = amo;
    list[count] = newNode;
    quicksort(list, 0, count);
    count++;
}