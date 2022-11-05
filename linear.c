#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt=0;

void ls(int a[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        cnt++;
        if(key==a[i])break;
    }
}

void analysis(int ch)
{
    srand(time(NULL));
    for(int i=10;i<=100;i+=10)
    {
        FILE *f;
        int *a=(int *)malloc(sizeof(int )*i);
        for(int j=0;j<i;j++)
            a[j]=rand()%100;
        int key;
        if(ch==1)
        {
            key=a[0];
            f=fopen("lsbest.txt","a");
        }
        if(ch==2)
        {
            key=999;
            f=fopen("lsworst.txt","a");
        }
        if(ch==3)
        {
            a[i/2]=999;
            key=a[i/2];
            f=fopen("lsavg.txt","a");
        }
        
        cnt=0;
        ls(a,i,key);
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

