#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int cnt=0;
int stringmatch(int text[],int pat[],int n,int m)
{
        int i,j;
    printf("Entered string match\n");
    for( i=0;i<n-m+1;i++)
    {
        for( j=0;j<m;j++)
        {
            cnt++;
            printf("%d\n",cnt);
            if(text[j+i]!=pat[j])break;
        }
        
        if(j==m)return i;
    }
    return -999;
}

void analysis(int ch)
{
    srand(time(NULL));
    for(int i=10;i<=100;i+=10)
    {
        FILE *f;
        int *a=(int*)malloc(sizeof(int)*i);
        for(int j=0;j<i;j++)
            a[j]=0;
        int pat[5];
        if(ch==1)
        {
           for(int j=0;j<5;j++)
            pat[j]=0;
            f=fopen("strbest.txt","a"); 
        }
        
         if(ch==2)
        {
           for(int j=0;j<5;j++)
            pat[j]=0;
            pat[4]=1;
            f=fopen("strworst.txt","a"); 
        }
        
         if(ch==3)
        {
           for(int j=0;j<5;j++)
            pat[j]=rand()%2;;
            f=fopen("stravg.txt","a"); 
        }
        cnt=0;
        int pos=stringmatch(a,pat,i,5);
        printf("%d",cnt);
        fprintf(f,"%d\t%d\n",i,cnt);
        fclose(f);
       // cnt=0;
    }
}

void main()
{
    int ch;
    for(;;)
    {printf("Enter choice\n");scanf("%d",&ch);analysis(ch);}
}
/*void main()
{
    char text[30],pat[10];
    printf("Enter text\n");
    scanf("%s",text);
    printf("Enter pattern\n");
    scanf("%s",pat);
    int i=stringmatch(text,pat,strlen(text),strlen(pat));
    printf("String pattern found at %d\n",i+1);
}*/

