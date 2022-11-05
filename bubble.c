#include<stdio.h>
#include<stdlib.h>

void bubble(int a[],int n)
{
    int flag;
    for(int i=0;i<n-1;i++)
    {
        flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                flag=1;
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if(flag==0)break;
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
    bubble(a,n);
     for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}













