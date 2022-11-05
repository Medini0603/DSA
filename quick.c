#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt=0;
int partition(int a[],int l,int h)
{
    int i=l+1,j=h,pivot=a[l];
    while(i<=j)
    {
        while(i<=h)
        {
            cnt++;
            if(a[i]>=pivot)break;
            i++;
        }
        
        while(j>=0)
        {
            cnt++;
            if(a[j]<=pivot)break;
            j--;
        }
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
        if(i==j&&pivot==a[j])
        {cnt++;return j;}
    }
    int temp=a[j];
    a[j]=a[l];
    a[l]=temp;
    return j;
}
void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
    int s=partition(a,l,h);
    quicksort(a,l,s-1);
    quicksort(a,s+1,h);
    }
}

void analysis(int ch)
{
    FILE *f;
    srand(time(NULL));
    for(int i=10;i<=100;i+=10)
    {
        int *a=(int*)malloc(sizeof(int)*i);
        if(ch==1)
        {
            for(int j=0;j<i;j++)
                a[j]=2;
            f=fopen("quickbest.txt","a");
        }
         if(ch==2)
        {
            for(int j=0;j<i;j++)
                a[j]=i+j+10;
            f=fopen("quickworst.txt","a");
        }
        
         if(ch==3)
        {
            for(int j=0;j<i;j++)
                a[j]=rand()%100;
            f=fopen("quickavg.txt","a");
        }
        cnt=0;
        quicksort(a,0,i-1);
        fprintf(f,"%d\t%d\n",i,cnt);
        fclose(f);
    }
}

void main()
{
    int ch;
    for(;;)
    {
        printf("Enter choice\n");
        scanf("%d",&ch);
        analysis(ch);
    }
}
/*void main()
{
    int n;
    printf("Ebter numebr of elemet\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        int l=0,h=n-1;
   quicksort(a,l,h);
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}*/


