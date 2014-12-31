using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

int cheaque[10];


int calculation(int a,int b)
{
    int temp,flag,i,k,count=0;



    for(i=a;i<=b;i++)
    {
        for(int m=0;m<10;m++)
            cheaque[m]=0;

        temp=i;
        flag=1;
        while(temp)
        {
            k=temp%10;
            if(cheaque[k]>0)
            {
                flag=0;
                break;
            }
            else
                cheaque[k]++;
            temp/=10;
        }
        if(flag)
            count++;
    }

    return count;
}

int main()
{
    int a,b;

    while(scanf("%d%d",&a,&b)==2)
    {
        printf("%d\n",calculation(a,b));
    }

    return 0;
}
