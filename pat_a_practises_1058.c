#include<stdio.h>
int main(){
    int g1,s1,k1;
    int g2,s2,k2;
    int t;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    k1=k1+k2;
    t=k1/29;
    k1%=29;
    s1=s1+s2+t;
    t=s1/17;               
    s1%=17;
    g1=g1+g2+t;
    printf("%d.%d.%d\n",g1,s1,k1);
    return 0;
}
