#include "product.h"
#include "manager.h"

int Menu(){
    int menu;
    printf("\n*** Menu ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu; 
}

void saveData(Product *p, int count) // File 저장 함수
{
    FILE *fp;
    fp = fopen("data.txt", "wt");
    for(int i=0; i<count; i++){
        if(p[i].weight == -1) continue;
        fprintf(fp, "%s %.2f %d %.1f %d\n", p[i].name, p[i].weight, p[i].price, p[i].star, p[i].star_count);
    }
    fclose(fp);
    printf("=> 저장됨!\n");
}

int loadData(Product *p) // File에서 데이터 불러오는 함수
{
    FILE *fp;
    if(fp = fopen("data.txt", "rt")){
        int i;
        for(i=0; i<100; i++){
            fscanf(fp, "%s", p[i].name);
            if(feof(fp)) break;
            fscanf(fp, "%f", &p[i].weight);
            fscanf(fp, "%d", &p[i].price);
            fscanf(fp, "%f", &p[i].star);
            fscanf(fp, "%d", &p[i].star_count);
        }
        printf("=> 로딩 성공!\n");
        fclose(fp);
        return i;
    }
    else{
        printf("=> 파일 없음\n");
        return 0;
    }
}

void searchName(Product *p, int count) // 제품 이름 검색
{
    char name[20];
    int flag=0;
    printf("검색할 이름? ");
    scanf("%s", name);
    printf("\n No Name Weight Price Rate RateCount\n================================\n");
    for(int i=0; i<count; i++){
        if(p[i].weight == -1) continue;
        if(strstr(p[i].name, name)){
            printf("%2d ", i+1);
            readScore(p[i]);
            flag++;
        }
    }
    if(flag == 0) printf("=> 검색된 데이터 없음!\n");
}

void searchPrice(Product *p, int count) // 제품 가격대 검색
{
    int price1, price2;
    int flag=0;
    printf("검색할 가격대? (최저 최고 입력) ");
    scanf("%d %d", &price1, &price2);
    printf("\n No Name Weight Price Rate RateCount\n================================\n");
    for(int i=0; i<count; i++){
        if(p[i].weight == -1) continue;
        if(price1<p[i].price && p[i].price<price2){
            printf("%2d ", i+1);
            readScore(p[i]);
            flag++;
        }
    }
    if(flag == 0) printf("=> 검색된 데이터 없음!\n");
}
	
void searchStar(Product *p, int count) // 제품 별점 검색
{
    char star;
    int flag=0;
    printf("검색할 별점? (최소치 입력) ");
    scanf("%d", &star);
    printf("\n No Name Weight Price Rate RateCount\n================================\n");
    for(int i=0; i<count; i++){
        if(p[i].weight == -1) continue;
        if(p[i].star>star){
            printf("%2d ", i+1);
            readScore(p[i]);
            flag++;
        }
    }
    if(flag == 0) printf("=> 검색된 데이터 없음!\n");
}

int main(){

#ifdef DEBUG
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

    Product p[20];
    int count = loadData(p);
    int index = count; //데이터 번호
    int menu;

    while(1){
        menu = Menu();
        if(menu==0) break;
        if(count > 20){
            printf("저장할 수 있는 최대 인원을 초과하였습니다.\n");
            continue;
        }
        if(menu==2){
            count += createProduct(&p[index++]);
        }
        else if(menu==1){
            listProduct(p, index);
        }
        else if(menu==3){
            int no = selectDataNo(p, index);
            if(no>0) updateProduct(&p[no-1]);
            else printf("취소됨!\n");
        }
        else if(menu==4){
            int no = selectDataNo(p, index);
            if(no>0){
                printf("정말로 삭제하시겠습니까? (삭제:1) ");
                int delok;
                scanf("%d", &delok);
                if(delok==1){
                    deleteProduct(&p[no-1]);
                    count--;
                    if(p[no-1].weight == -1) printf("삭제됨!\n");
                }
            }
            else printf("취소됨!\n");
        }
	else if(menu==5){
	    saveData(p, index);
	}
	else if(menu==6){
            int type;
            printf("어느 타입으로 검색하시겠습니까?(1: 이름, 2: 가격대, 3: 별점) ");
            scanf("%d", &type);
            if(type==1) searchName(p, index);
            else if(type==2) searchPrice(p, index);
            else if(type==3) searchStar(p, index);
            else printf("잘못 입력하셨습니다.\n");
        }
    }
    printf("종료됨!\n");
    return 0;
}
