#include<stdio.h>
#include<stdlib.h>
int cnt=0;
int min(int a,int b)
{
    if(a>b)return b;
    else return a;
}
void floyds(int *a[],int n)
{
    cnt=0;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {   
            
            
                for(int j=0;j<n;j++)
                {
                   
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                }
            
        }
    }
}

void main()
{
    int n;
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    int* a[n],*tc[n];
    for(int i=0;i<n;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*n);
        tc[i]=(int*)malloc(sizeof(int)*n);
    }
    printf("Enter adjcacency matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            tc[i][j]=a[i][j];
        }
    }
    printf("All pairs shortest path\n");
    floyds(tc,n);
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",tc[i][j]);
            //tc[i][j]=a[i][j];
        }
        printf("\n");
    }
}



