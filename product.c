#include "product.h"

int createProduct(Product *p){ // 제품을 추가하는 함수
    printf("제품명은? : ");
    scanf("%s",p->name);
    printf("중량은?(g) : ");
    scanf("%f",&p->weight);
    p->weight = p->weight/1000.0; //kg으로 변경
    printf("판매가격은? : ");
    scanf("%d",&p->price);
    printf("별점은?(1~5) : ");
    scanf("%f",&p->star);
    printf("별점개수는? : ");
    scanf("%d",&p->star_count);
    return 1;
}
void readProduct(Product p){ // 하나의 제품 출력 함수
    printf("%s %.2fkg %d원 %.1f점(%d개)\n", p.name, p.weight, p.price, p.star, p.star_count);
}
int updateProduct(Product *p){ // 제품을 수정하는 함수
    printf("제품명은? : ");
    scanf("%s",p->name);
    printf("중량은?(g) : ");
    scanf("%f",&p->weight);
    p->weight = p->weight/1000.0; //kg으로 변경
    printf("판매가격은? : ");
    scanf("%d",&p->price);
    printf("별점은?(1~5) : ");
    scanf("%f",&p->star);
    printf("별점개수는? : ");
    scanf("%d",&p->star_count);
    printf("수정 성공!\n");
    return 1;
}
int deleteProduct(Product *p){ // 하나의 제품을 삭제하는 함수
    p->weight = -1;
    p->price = -1;
    p->star = -1;
    return 1;
}
