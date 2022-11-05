#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int q,r,f,cnt,*arr;
}QUE;

void indegree(int *a[],int v,QUE* q,int inq[],int flag[])
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(a[j][i]==1)inq[i]=inq[i]+1;
        }
    }
    
    for(int i=0;i<v;i++)
    {
         if(inq[i]==0)
         {
            q->r=(q->r+1)%v;
            q->arr[q->r]=i;
            q->cnt++;
            flag[i]=1;
         }
    }
}

void sourcerem(int* a[],int v,QUE* q,int inq[],int flag[])
{
    int cnt=0;
    while(q->cnt!=0)
    {
        int source=q->arr[q->f];
        q->f=(q->f+1)%v;
        q->cnt--;
        printf("%d\t",source+1);
        cnt++;
        
        for(int i=0;i<v;i++)
        {
            if(a[source][i]==1)inq[i]=inq[i]-1;
            
            if(inq[i]==0 &&flag[i]==0)
            {
                q->r=(q->r+1)%v;
                q->arr[q->r]=i;
                q->cnt++;
                flag[i]=1;
            }
        }
    }
    
    if(cnt!=v)
        printf("Cycles exist topo not possible\n");
}

void main()
{
    int n;
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    int* a[n];
    int inq[n],flag[n];
    QUE q;
    q.f=0,q.r=-1,q.cnt=0;
    q.arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*i);
        inq[i]=0;
        flag[i]=0;
    }
    printf("Enter adj mat\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    indegree(a,n,&q,inq,flag);
    printf("Topological sorting\n");
    sourcerem(a,n,&q,inq,flag);
}















