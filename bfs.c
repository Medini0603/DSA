#include<stdio.h>
#include<stdlib.h>
int count=0;
typedef struct queue
{
    int *arr,f,r,cnt;
}QUE;
void dfs(int *a[],int n,int v,int vis[],int parent[])
{
    QUE q;
    q.f=0,q.r=-1,q.cnt=0;
    q.arr=(int*)malloc(sizeof(int)*n);
    
    count++;
    vis[v]=count;
    
    printf("Vertex %d %d\n",v+1,vis[v]);
    
    q.r=(q.r+1)%n;
    q.arr[q.r]=v;
    q.cnt++;
    
    while(q.cnt!=0)
    {
        int ver=q.arr[q.f];
        q.f=(q.f+1)%n;
        q.cnt--;
        for(int i=0;i<n;i++)
        {
            if(a[ver][i]==1 &&vis[i]==0)
            {
            
                parent[i]=ver;
                count++; 
                vis[i]=count;
                printf("Vertex %d %d\n",i+1,vis[i]);
                
                q.r=(q.r+1)%n;
                q.arr[q.r]=i;
                q.cnt++;
                
            }
        }
    }
}

void cycle(int* a[],int n,int parent[],int vis[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1 && parent[i]!=j && vis[i]>vis[j])
                {printf("cycle exists\n");return;}
        }
    }
    printf("No cycles\n");
}

int DFS(int *a[],int n,int vis[],int parent[])
{
    int cflag=0;
    count=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            parent[i]=-1;
            cflag++;
            printf("Connected component %d\n",cflag);
            dfs(a,n,i,vis,parent);
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
  cycle(a,n,parent,vis);
}










