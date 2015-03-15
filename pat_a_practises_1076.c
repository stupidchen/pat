#include<stdio.h>
#define maxn 1011
int a[maxn][maxn],ans[maxn];
int queue[maxn],dis[maxn];    
int main(){
    int i,j,h,t,t2,q;
    int s,n,l,d,k;
    
    for (i=1;i<maxn;i++){
        ans[i]=-1;
        for (j=1;j<maxn;j++) a[i][j]=-1;
    }
    scanf("%d%d",&n,&l);
    for (i=1;i <= n;i++){
        scanf("%d",&t);
        for (j=0;j<t;j++){
            scanf("%d",&t2);
            a[t2][i]=1;
        }
    }
    scanf("%d",&k);
    for (q=0;q<k;q++){
        scanf("%d",&d);
        if (ans[d] == -1){
           for (i=1;i <= n;i++) dis[i]=-1;
           dis[d]=0;
           h=0;t=1;
           queue[1]=d;
           while (h++<t){
                 for (i=1;i <= n;i++)
                     if ((a[queue[h]][i] != -1) && ((dis[queue[h]]+1<dis[i]) || (dis[i] == -1))){
                        dis[i]=dis[queue[h]]+1;
                        if (dis[i]<l) queue[++t]=i;
                     }
           }
           s=0;
           for (i=1;i <= n;i++) 
               if ((dis[i] <= l) && (dis[i]>0)) s++;
           ans[d]=s;
        }
        printf("%d\n",ans[d]);
    }
    return 0;
}
