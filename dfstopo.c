#include<stdio.h>
#include<stdlib.h>
int count=0;
int t=0;
int dfs(int *a[],int n,int v,int vis[],int topo[],int parent[])
{
    count++;
    vis[v]=count;
    
    for(int i=0;i<n;i++)
    {
        if(a[v][i]==1 &&vis[i]==0)
        {
            parent[i]=v;
            dfs(a,n,i,vis,topo,parent);
        }
    }
    topo[t++]=v+1;
}

int DFS(int *a[],int n,int vis[],int topo[],int parent[])
{
    int cflag=0;
    count=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            parent[i]=-1;
            cflag++;
            dfs(a,n,i,vis,topo,parent);
        }
    }
}

void cycle(int* a[],int n,int parent[],int vis[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1 && vis[i]>vis[j] && parent[i]!=j)
            {
                printf("Cycles exist topo not possible\n");
                exit(0);
            }
        }
    }
    
}
void main()
{
    int n;
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    int* a[n];
    int topo[n];
    int vis[n];
    int parent[n];
    for(int i=0;i<n;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*i);
        topo[i]=-1;
        vis[i]=0;
        parent[i]=-1;
    }
    printf("Enter adj mat\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    DFS(a,n,vis,topo,parent);
    cycle(a,n,parent,vis);
    for(int i=0;i<n;i++)
    printf("%d",parent[i]);
    printf("Topological sorting\n");
   for(int i=n-1;i>=0;i--)
    printf("%d\t",topo[i]);
}



























