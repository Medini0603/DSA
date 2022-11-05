#include<stdio.h>
#include<stdlib.h>
typedef struct label
{
    int l1,l2,flag;
}label;
int prims(int *a[],int n)
{
    label l[n+1];
    for(int i=1;i<=n;i++)
    {
        l[i].l1=0;
        l[i].l2=999;
        l[i].flag=0;
    }
    
    int vertex[n+1];
    vertex[0]=1;
    l[1].flag=1;
    int i=1;
    for(int i=2;i<=n;i++)
    {
        l[i].l1=1;
        l[i].l2=a[1][i];
    }
    
    int min,minin;
    printf("Minimum spanning tree\n");
    int sum=0;
    for(int i=1;i<n;i++)
    {
        min=9999;
        for(int j=1;j<=n;j++)
        {
            if(l[j].flag==1)continue;
            if(min>l[j].l2)
            {
                 minin=j;
                 min=l[j].l2;
            }
        }
        
        //vertex[i++]=minin;
        l[minin].flag=1;
        printf("(%d , %d)\n",l[minin].l1,minin);
        sum+=min;
        
        for(int i=1;i<=n;i++)
        {
            if(l[i].flag==1)continue;
            if(l[i].l2>a[minin][i])
            {
                l[i].l1=minin;
                l[i].l2=a[minin][i];
            }
        }
    }
 return sum;   
}

void main()
{
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    int *a[n+1];
    for(int i=0;i<=n;i++)
        a[i]=(int*)malloc(sizeof(int)*n+1);
    printf("Enter the adjacency matrix\n");
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int sum=prims(a,n);
    printf("\nWeight of MST= %d\n",sum);
}



