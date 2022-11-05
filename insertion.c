#include<stdio.h>
#include<stdlib.h>

void insertion(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1,v=a[i];
        while(j>=0)
        {
            if(a[j]<=v)break;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
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
    insertion(a,n);
     for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}













