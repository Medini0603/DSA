#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt=0;
void data(int a[],int n)
{
    if(n==1||n==2)return;
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        a[i]=a[n-1];
        a[n-1]=temp;
    }
}
void merge(int a[],int b[],int c[],int p,int q)
{
    int i=0,k=0,j=0;
    while(i<p && j<q)
    {
        cnt++;
        if(b[i]>=c[j])
        {
            a[k]=c[j];
            j++;k++;
        }
        else
        {
            a[k]=b[i];
            i++;k++;
        }
    }
    
    if(i==p)
    {
        while(j<q)
        {
            a[k]=c[j];
            k++;j++;
        }
    }
    else
    {
        while(i<p)
        {
            a[k]=b[i];
            k++;i++;
        }
    }
}
void mergesort(int a[],int n)
{
    if(n>1)
    {
        int m1=n/2,m2=n-(n/2);
        int b[m1],c[m2];
        for(int i=0;i<m1;i++)
            b[i]=a[i];
        for(int j=0;j<m2;j++)
            c[j]=a[j+m1];
        
        mergesort(b,m1);
        mergesort(c,m2);
        merge(a,b,c,m1,m2);
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
                a[j]=i+j+10;
            f=fopen("mergebest.txt","a");
        }
         if(ch==2)
        {
            int e=2,o=1;
            int b[i/2];
            for(int j=0;j<i/2;j++)
               {
                    a[j]=e;
                    e+=2;
               }
              for(int j=0;j<i/2;j++)
               {
                    b[j]=o;
                    o+=2;
               }
               
               data(a,i/2);
               data(b,i/2);
               for(int j=0;j<i/2;j++)
                a[j+(i/2)]=b[j];
            f=fopen("mergeworst.txt","a");
        }
        
         if(ch==3)
        {
            for(int j=0;j<i;j++)
                a[j]=rand()%100;
            f=fopen("mergeavg.txt","a");
        }
        cnt=0;
       mergesort(a,i);
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
       for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
        printf("\n");
   mergesort(a,n);
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}*/


