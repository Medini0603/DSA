#include<stdio.h>
#include<stdlib.h>
int count=0;
void dfs(int *a[],int n,int v,int vis[],int parent[])
{
    count++;
    vis[v]=count;
    printf("Vertex %d -> %d\n",v+1,vis[v]);
    for(int i=0;i<n;i++)
    {
        if(a[v][i]==1 && vis[i]==0)
        {
            parent[i]=v;
            dfs(a,n,i,vis,parent);
        }
    }    
}

void cycle(int *a[],int n,int parent[],int vis[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1 && parent[i]!=j && vis[i]>vis[j])
            {
                printf("Cycle exists\n");
                return;
            }
        }
    }
    printf("Cycle does not exist\n");
}

int DFS(int *a[],int n,int vis[],int parent[])
{
    count=0;
    int cflag=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            parent[i]=-1;
            cflag++;
            printf("Connected component %d\n",cflag);
            dfs(a,n,i,vis,parent);
            printf("\n");
        }
    }
    return cflag;
}

void main()
{
    int n;
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    int* a[n];
    int vis[n];
   int parent[n];
    for(int i=0;i<n;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*n);
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
    
  int flag= DFS(a,n,vis,parent);
  if(flag==1)
  {
    printf("Connected\n");
    
  }
  else printf("Not connected\n");
  for(int i=0;i<n;i++)
    printf("%d\t",parent[i]);
  cycle(a,n,parent,vis);
}










