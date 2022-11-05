#include<stdio.h>
#include<stdlib.h>

typedef struct label
{
    int l1,l2,flag;
}label;
int cnt=0;
int prims(int* a[],int n)
{
    cnt=0;
    label l[n+1];
    for(int i=1;i<=n;i++)
    {
        l[i].l1=-1;
        l[i].l2=1000;
        l[i].flag=0;
    }
    
    int vertex[n];
    vertex[0]=1;
    l[1].flag=1;
    for(int i=2;i<=n;i++)
    {
        l[i].l1=1;
        l[i].l2=a[1][i];
    }
    
        int minin,min;
        int sum=0;
    for(int i=1;i<n;i++)
    {
        min=9999;
        for(int j=1;j<=n;j++)
        {
            if(l[j].flag==1)continue;
                cnt++;
            if(min>l[j].l2)
            {
                minin=j;
                min=l[j].l2;
            }
        }
        
        vertex[i]=minin;
        l[minin].flag=1;
        printf("(%d %d)\n",l[minin].l1,minin);
        sum+=min;
        
        for(int j=1;j<=n;j++)
        {
            if(l[j].flag==1)continue;
                cnt++;
            if(l[j].l2>a[minin][j])
            {
                l[j].l1=minin;
                l[j].l2=a[minin][j];
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
    printf("%d\n",cnt);
}





