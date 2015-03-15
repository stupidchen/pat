#include<stdio.h>
#define maxn 1010
struct poly{
       double co[maxn];
       int n;
};
struct poly a,b;
void init(){
     int i,e;
     scanf("%d",&a.n);
     for (i=0;i<a.n;i++){
         scanf("%d ",&e);
         scanf("%lf",&(a.co[e]));
     }
     scanf("%d",&b.n);
     for (i=0;i<b.n;i++){
         scanf("%d ",&e);
         scanf("%lf",&(b.co[e]));
     }
}
void process(){
     int i,n=0;
     double f;
     for (i=0;i<maxn;i++){
         a.co[i]+=b.co[i];
         if (a.co[i] != 0) n++;
     }
     printf("%d",n);
     for (i=maxn-1;i>=0;i--) 
         if (a.co[i] != 0) 
         printf(" %d %.1lf",i,a.co[i]);
}
int main(){
    init();
    process();
    return 0;
}
