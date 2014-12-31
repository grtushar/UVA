using namespace std;

#include<iostream>
#include<cstdio>

int absolute(int x)
{
        if(x<0)
                return -x;
        return x;
}
int main()
{
        int a,b;

        while(cin>>a>>b)
        {
                if(a==-1&&b==-1)
                        break;
                int ans=absolute(a-b);
                if(ans>=50)
                        ans=100-ans;
                printf("%d\n",ans);
        }

        return 0;
}
