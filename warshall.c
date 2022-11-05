#include<stdio.h>
#include<stdlib.h>
int cnt=0;
void warshall(int *a[],int n)
{
    cnt=0;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {   
            cnt++;
            if(a[i][k]==1)
            {
            
                for(int j=0;j<n;j++)
                {
                    cnt++;
                    if(a[i][j]==1)a[i][j]=1;
                    if(a[k][j]==1)a[i][j]=1;
                }
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
    printf("Transitive closure\n");
    warshall(tc,n);
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



