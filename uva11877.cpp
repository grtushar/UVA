using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
        int n,cnt,temp;

        while(scanf("%d",&n)&&n)
        {
                cnt=n/3;
                temp=cnt+n%3;

                while(temp>=3)
                {
                        cnt+=temp/3;
                        temp=temp%3+temp/3;
                }

                if(temp==2) cnt+=1;

                printf("%d\n",cnt);
        }

        return 0;
}
