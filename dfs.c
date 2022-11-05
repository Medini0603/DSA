#include<stdio.h>
#include<stdlib.h>
int count=0;
void dfs(int *a[],int n,int v,int vis[])
{
    count++;
    vis[v]=count;
    printf("Vertex %d -> %d\n",v+1,vis[v]);
    for(int i=0;i<n;i++)
    {
        if(a[v][i]==1 && vis[i]==0)
            dfs(a,n,i,vis);
    }    
}

int DFS(int *a[],int n,int vis[])
{
    count=0;
    int cflag=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            cflag++;
            printf("Connected component %d\n",cflag);
            dfs(a,n,i,vis);
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
   
    for(int i=0;i<n;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*n);
        vis[i]=0;
        
    }
    printf("Enter adj mat\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
  int flag= DFS(a,n,vis);
  if(flag==1)
  {
    printf("Connected\n");
    
  }
  else printf("Not connected\n");
}










