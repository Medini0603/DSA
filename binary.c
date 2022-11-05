#include<stdio.h>
#include<stdlib.h>

void binary(int a[],int l,int h,int key)
{
    if(l>h)return ;
    int m=(l+h)/2;
    if(key==a[m]){printf("Key found at %d\n",m+1);return ;}
    if(key>a[m]) binary(a,m+1,h,key);
    else binary(a,l,m-1,key);
    
  //  return -999;
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
    int key;
    printf("Enter key\n");
    scanf("%d",&key);
     for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
   binary(a,0,n-1,key);
    printf("\n");
}













