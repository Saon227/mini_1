#ifndef _MANAGER_H_

#define _MANAGER_H_
#include <stdio.h>
#include "product.h"

void listProduct(Product *p, int count); // 전체 등록된 제품 리스트 출력
int selectDataNo(Product *p, int count);

#endif
