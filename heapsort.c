#include<stdio.h>
#include<stdlib.h>
int cnt=0;
void heapify(int a[],int n)
{
    int k,heap,v,j;
    for(int i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k];
        heap=0;
        
        while(!heap && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                cnt++;
                if(a[j+1]>a[j])j++;
            }
            cnt++;
            if(v>=a[j])heap=1;
            else
            {
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
    }
}

void sort(int a[],int n)
{
   heapify(a,n);
    int size=n;
    for(int i=1;i<size;i++)
    {
        int temp=a[n];
        a[n]=a[1];
        a[1]=temp;
        n--;
        int heap=0,j,k,v;
    
       k=1;
       v=a[k];
       heap=0;
      while(!heap && 2*k<=n)
      {
        j=2*k;
        if(j<n)
        {
            cnt++;
            if(a[j+1]>a[j])j++;   
        }
        cnt++;
        if(v>=a[j])heap=1;
        else
        {
            a[k]=a[j];
            k=j;
        }
      }
      a[k]=v;
    }
}

void analysis(int ch)
{
    FILE* f;
    for(int i=11;i<=101;i+=10)
    {
        int *a=malloc(sizeof(int)*i);
        if(ch==1)
        {
            for(int j=1;j<i;j++)
                a[j]=i-j+10;
            f=fopen("heapbest.txt","a");
        }
         
        if(ch==2)
        {
            for(int j=1;j<i;j++)
                a[j]=i+j+10;
            f=fopen("heapworst.txt","a");
        }
        
        if(ch==3)
        {
            for(int j=1;j<i;j++)
                a[j]=rand()%100;
            f=fopen("heapavg.txt","a");
        }
        cnt=0;
        sort(a,i-1);
        fprintf(f,"%d\t%d\n",i-1,cnt);
        fclose(f);
    }
    
}


void main()
{
    int ch;
    for(;;)
    {
        printf("Enter choice\n1->best\n2->worst\n3->avg\n");
        scanf("%d",&ch);
        analysis(ch);
    }
}
/*void main()
{
    int n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter elements\n");
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a,n);
    printf("After sorting\n");
    for(int i=1;i<=n;i++)
        printf("%d\t",a[i]);
    printf("\n");
}*/

















