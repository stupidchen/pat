#include<stdio.h>
#define maxn 21110
int n,m,c;
int t_edge[maxn][3],edge[maxn][2],head[maxn];
int set[maxn],component[maxn];
int dis1[maxn],dis2[maxn],q[maxn],can[maxn];
int find(int x){
    if (set[x] == x) return x;
    set[x]=find(set[x]);
    return set[x];
}
void merge(int x,int y){
     x=find(x);
     y=find(y);
     if (x%2 == 0) set[y]=set[x];
     else set[x]=set[y];
}
void add_edge(int x,int y){
     m++;
     edge[m][0]=head[x];
     edge[m][1]=y;
     head[x]=m;
}
int main(){
    int i,j,k,s;
    int h,t;
    int temp0,temp1,maxdis1,maxdis2;

    scanf("%d",&n);
    m=0;
    for (i=1;i<n;i++){
        scanf("%d%d",&t_edge[i][1],&t_edge[i][2]);
        add_edge(t_edge[i][1],t_edge[i][2]);
        add_edge(t_edge[i][2],t_edge[i][1]);        
    }
    
    for (i=1;i<=n;i++) set[i]=i;
    for (i=1;i<n;i++) merge(t_edge[i][1],t_edge[i][2]);
    for (i=1;i<=n;i++) component[find(i)]=1;
    s=0;
    for (i=1;i<=n;i++) s+=component[i];
    if (s != 1){
       printf("Error: %d components\n",s);
       return 0;
    }
    
    q[1]=1;
    h=0;t=1;
    for (i=2;i<=n;i++) dis1[i]=-1;
    dis1[1]=0;
    maxdis1=0;
    while (h++<t){
          k=head[q[h]];
          maxdis1=maxdis1>dis1[q[h]]?maxdis1:dis1[q[h]];
          while (k != 0){
                temp0=edge[k][1];
                if (dis1[temp0] == -1){
                   dis1[temp0]=dis1[q[h]]+1;
                   q[++t]=temp0;
                }
                k=edge[k][0];
          }
    }
    
    for (i=1;i<=n;i++)
        if (dis1[i] == maxdis1) can[i]=1;
    for (i=1;i<=n;i++)
        if (can[i]) break;
    
    q[1]=i;
    h=0;t=1;
    for (j=1;j<=n;j++) dis2[j]=-1;
    dis2[i]=0;
    maxdis2=0;
    while (h++<t){
          k=head[q[h]];
          maxdis2=maxdis2>dis2[q[h]]?maxdis2:dis2[q[h]];
          while (k != 0){
                temp0=edge[k][1];
                if (dis2[temp0] == -1){
                   dis2[temp0]=dis2[q[h]]+1;
                   q[++t]=temp0;
                }
                k=edge[k][0];
          }
    }
    for (j=1;j<=n;j++) 
        if (dis2[j] == maxdis2) can[j]=1;

    for (i=1;i<=n;i++)
        if (can[i]) printf("%d\n",i);
    return 0;
}
