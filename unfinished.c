#include<stdio.h>
#define maxn 100010

void merge(int *s0,int *s1,int *s2,int l1,int l2){
     int p0,p1,p2,t1,t2;
     p0=0;
     p1=0;
     p2=0;
     while (p1<l1 && p2<l2){
          t1=*(s1+p1);
          t2=*(s2+p2);
          if (t1<t2){
             *(s0+p0++)=t1;
             p1++;
          }
          else{
               *(s0+p0++)=t2;
               p2++;
          }
     }
     while (p1<l1) *(s0+p0++)=*(s1+p1++);
     while (p2<l2) *(s0+p0++)=*(s2+p2++);
}
void sort(int *w,int x,int y){
     int i,j,k,t1,t2;
     for (i=x;i<=y;i++){
         if (*(w+i)>*(w+i+1)) t1=
     }
}
int main(){
    int n,p;
    int a[maxn],temp[maxn];
    scanf("%d%d",&n,&p);
    for (i=0;i<n;i++) scanf("%d",a[i]);
    
    sort(&a,0,n-1);
}
