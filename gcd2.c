#include<stdio.h>
#include<stdlib.h>
int cnt=0;
void euclid(int m,int n)
{
    while(n>0)
    {
        cnt++;
        int r=m%n;
        m=n;
        n=r;
    }
}

void modeu(int m,int n)
{
    while(n>0)
    {
        cnt++;
        if(n>m)
        {
            int t=m;
            m=n;
            n=t;
        }
        m=m-n;
    }
}
void consint(int m,int n)
{
    int min;
    if(m<n)min=m;
    else min=n;
    
    while(min>0)
    {
        cnt++;
        if(m%min == 0 &&n%min==0)
        break;
        min--;
    }
}
void main()
{
    FILE *f1,*f2;
    for(int i=10;i<=100;i+=10)
    {
        int min=999,max=-1;
        int min2=999,max2=-1;
        int min3=999,max3=-1;
        for(int j=2;j<=i;j++)
        {
            for(int k=2;k<=i;k++)
            {
                cnt=0;
                euclid(j,k);
                if(min>cnt)min=cnt;
                if(max<cnt)max=cnt;
                
                cnt=0;
                modeu(j,k);
                if(min2>cnt)min2=cnt;
                if(max2<cnt)max2=cnt;
                
                cnt=0;
                consint(j,k);
                if(min3>cnt)min3=cnt;
                if(max3<cnt)max3=cnt;
            }
        }
        
        f1=fopen("Ebest.txt","a");
        f2=fopen("Eworst.txt","a");
        
        fprintf(f1,"%d\t%d\n",i,min);
        fprintf(f2,"%d\t%d\n",i,max);
        fclose(f1);
        fclose(f2);
        
         f1=fopen("MEbest.txt","a");
        f2=fopen("MEworst.txt","a");
        
        fprintf(f1,"%d\t%d\n",i,min2);
        fprintf(f2,"%d\t%d\n",i,max2);
        fclose(f1);
        fclose(f2);
        
          f1=fopen("Cbest.txt","a");
        f2=fopen("Cworst.txt","a");
        
        fprintf(f1,"%d\t%d\n",i,min3);
        fprintf(f2,"%d\t%d\n",i,max3);
        fclose(f1);
        fclose(f2);
    }
}






