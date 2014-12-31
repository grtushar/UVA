using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
    int n,k,i,temp,ans;

    while(scanf("%d%d",&n,&k)!=EOF)
    {
        temp=(n/k)+n%k;
        ans=n+(n/k);

        while(temp>=k)
        {
            ans+=(temp/k);
            temp=(temp/k)+(temp%k);
        }

        printf("%d\n",ans);
    }

    return 0;
}
