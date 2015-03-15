#include<stdio.h>
#define maxn 100010
int n,m;
int a[maxn],f1[maxn],f2[maxn];
int main(){
    int i,j,k,s,e,dis1,dis2;
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    
    for (i=2;i<=n;i++) f1[i]=f1[i-1]+a[i-1];
    for (i=n;i>0;i--) f2[i]=f2[i+1]+a[i];
    
    scanf("%d",&m);
    for (i=1;i<=m;i++){
        scanf("%d%d",&s,&e);
        if (s>e){
           k=s;s=e;e=k;
        }
        dis1=f1[e]-f1[s];
        dis2=f2[e]+f1[s];
        printf("%d\n",dis1>dis2?dis2:dis1);
    }
    return 0;
}
