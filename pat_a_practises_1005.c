#include<stdio.h>
void print(int x,int y){
     if (x == 0) return;
     print(x/10,1);
     switch (x%10){
            case 0:printf("zero");break;
            case 1:printf("one");break;
            case 2:printf("two");break;               
            case 3:printf("three");break;
            case 4:printf("four");break;
            case 5:printf("five");break;
            case 6:printf("six");break;
            case 7:printf("seven");break;                                                                           
            case 8:printf("eight");break;
            case 9:printf("nine");break;                              
     }
     if (y) printf(" ");     
     return;
}
int main(){
    char c;
    int t,s;
    scanf("%c",&c);
    t=0;
    s=0;
    while ((c >= '0') && (c <= '9')){
        s=s+c-'0';
        scanf("%c",&c);
    }
    if (s == 0) printf("zero");
    else print(s,0);
    printf("\n");
    return 0;
}
