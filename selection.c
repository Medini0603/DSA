#include<stdio.h>
#include<stdlib.h>

void selection(int a[],int n)
{
    int min,j;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
               min=j;
            }
        }
        
        if(min!=i)
        {
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}

void main()
{
    int n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
     for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    selection(a,n);
     for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}













