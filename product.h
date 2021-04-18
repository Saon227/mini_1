#ifndef _PRODUCT_H_

#define _PRODUCT_H_
#include <stdio.h>
typedef struct{
    char name[20]; // 제품명
    float weight; // 중량
    int price; // 판매가격
    float star; // 별점(1~5)
    int star_count; // 별점개수
} Product;

int createProduct(Product *p); // 제품을 추가하는 함수
void readProduct(Product p); // 하나의 제품 출력 함수
void listProduct(Product *p, int count); // 전체 등록된 제품 리스트 출력
int updateProduct(Product *p); // 제품을 수정하는 함수
int deleteProduct(Product *p); // 하나의 제품을 삭제하는 함수
void saveData(Product *p, int count); // File 저장 함수
int loadData(Product *p); // File에서 데이터 불러오는 함수
void searchName(Product *p, int count); // 제품 이름 검색
void searchPrice(Product *p, int count); // 제품 가격대 검색
void searchStar(Product *p, int count); // 제품 별점 검색

#endif
