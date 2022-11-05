#include<stdio.h>
#include<stdlib.h>

int cnt=0;
int cnt2=0;
int cnt3=0;
void euclid(int m,int n)
{
    printf("Entered euclid\n");
    while(n>0)
    {
        cnt++;
        int r=m%n;
        m=n;
        n=r;
        cnt++;
    }
}

void modeu(int m,int n)
{
    while(n>0)
    {
        if(n>m)
        {
            cnt2++;
            int t=m;
            m=n;
            n=t;
        }
        m=m-n;
    }
}

void conint(int m,int n)
{
    int min;
    if(m<n)min=m;
    else min=n;
    
    while(min>0)
    {
        cnt3++;
        if(m%min==0||n%min==0)break;
        min--;
    }
}

void analysis(int ch)
{
    FILE* f1,*f2;
    int min=999,max=0;
    for(int i=10;i<=100;i+=10)
    {
                min=999,max=0;
                
        for(int j=2;j<=i;j++)
        {
            for(int k=2;k<=i;k++)
            {
                cnt=0;
                cnt2=0;
                cnt3=0;
                if(ch==1)
                {
                    
                    euclid(j,k);
                    if(min>cnt)min=cnt;
                    if(max<cnt)max=cnt;
                    
                }
                
                if(ch==2)
                {
                    
                    modeu(j,k);
                    if(min>cnt2)min=cnt2;
                    if(max<cnt2)max=cnt2;
                    
                }
                
                if(ch==3)
                {
                   
                    conint(j,k);
                    if(min>cnt3)min=cnt3;
                    if(max<cnt3)max=cnt3;
                    
                }
            }
        }
        
        if(ch==1)
        {
            f1=fopen("eucbest.txt","a");
            f2=fopen("eucworst.txt","a");
        }
        
        if(ch==2)
        {
            f1=fopen("mebest.txt","a");
            f2=fopen("meworst.txt","a");
        }
        if(ch==3)
        {
            f1=fopen("conbest.txt","a");
            f2=fopen("conworst.txt","a");
        }
        fprintf(f1,"%d\t%d\n",i,min);
        fclose(f1);
        fprintf(f2,"%d\t%d\n",i,max);
        fclose(f2);
    }
}

void main()
{int ch;
    for(;;)
    {
        printf("Entr ch\n");
        scanf("%d",&ch);
        analysis(ch);
    }
}

