#include<stdio.h>
int a,b;
void print(int x,int y){
     if (x == 0) return;
     print(x/10,y+1);
     printf("%d",x%10);
     if ((y%3 == 0) && (y != 0)) printf(",");     
}
int main(){
    scanf("%d%d",&a,&b);
    a=a+b;
    if (a<0){
             printf("-");
             print(-a,0);
    }
    else{
         if (a == 0) printf("0");
            else print(a,0);
    }
    return 0;
}
