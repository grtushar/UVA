using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

int main()
{
        long long n,t;
        int arr[8]={2,3,4,5,6,7,8,9};
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld",&n);
                vector<int>ans;
                ans.clear();

                if(n<10)
                {
                        printf("%lld\n",n);
                }
                else
                {
                        int i;
                        for(i=7;i>=0;i--)
                        {
                                while(n%arr[i]==0)
                                {
                                        ans.push_back(arr[i]);
                                        n/=arr[i];
                                }
                                if(n==1)
                                        break;
                        }

                        if(n==1)
                        {
                                int sz=ans.size();
                                for(i=sz-1;i>=0;i--)
                                        printf("%d",ans[i]);
                                printf("\n");
                        }
                        else
                                printf("-1\n");
                }
        }

        return 0;
}
