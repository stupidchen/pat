#include<stdio.h>
#define maxn 101
int main(){
    int n,m,i,j,k,t0,t1,t2;
    int father[maxn],son[maxn],level[maxn],stack[maxn];
    
    scanf("%d%d",&n,&m);
    for (i=0;i<=n;i++){
        father[i]=0;
        son[i]=0;
        level[i]=0;
    }
    for (i=0;i<m;i++){
        scanf("%d%d",&t0,&t1);
        for (j=0;j<t1;j++){
            scanf("%d",&t2);
            father[t2]=t0;
        }
    }
    for (i=1;i<=n;i++){
        t0=father[i];
        t1=level[i];
        stack[0]=1;
        stack[1]=i;
        while (t0 != 0){
              son[t0]=1;
              stack[++stack[0]]=t0;
              t0=father[t0];
        }
        stack[++stack[0]]=0;
        while (stack[0]-->1) level[stack[stack[0]]]=level[stack[stack[0]+1]]+1;
    }

    t1=0;
    for (i=1;i<=n;i++){
        k=0;
        t0=0;
        for (j=1;j<=n;j++)
            if (level[j] == i){
               t0=1;
               if (!son[j]) k++;
            }
        if (t0){
           if (t1) printf(" ");
           else t1=1;
           printf("%d",k);
        }
    }
    return 0;
}
