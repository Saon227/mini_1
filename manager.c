#include "product.h"
#include "manager.h"

void listProduct(Product *p, int count){ // 전체 등록된 제품 리스트 출력
    printf("Name Weight Price Rate RateCount\n================================\n");
        for(int i=0; i<count; i++){
            if(p[i].weight == -1) continue;  //삭제된 경우
            printf("%2d ", i+1);
            readProduct(p[i]);
        }
}
int selectDataNo(Product *p, int count){
    listProduct(p, count);
    int num;
    printf("\n번호는 (취소 :0)? ");
    scanf("%d", &num);
    return num;
}
