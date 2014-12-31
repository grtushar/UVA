using namespace std;

#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
#include<algorithm>

typedef long long int ll_d;

vector<ll_d>red,blue;

/*lld absolute(lld x)
{
        if(x<0)
                return -x;
        return x;
}*/

int main()
{
        ll_d t,n,i,j,count,x,l1,l2;
        scanf("%lld",&t);

        while(t--)
        {
                l1=l2=0;
                scanf("%lld",&n);
                red.clear();
                blue.clear();

                for(i=0;i<n;i++)
                {
                        scanf("%lld",&x);
                        if(x<0)
                        {
                                red.push_back(-x);
                                l1++;
                        }
                        else
                        {
                                blue.push_back(x);
                                l2++;
                        }
                }

                sort(red.begin(),red.end());
                sort(blue.begin(),blue.end());

                int flag;
               count=1;
               i=j=0;

                if(blue[0]>red[0])
                        flag=0;
                else
                        flag=1;

                while(1)
                {
                        if(flag)
                        {
                                while(i<l1&&blue[j]>=red[i])
                                {
                                        i++;
                                }

                                if(i==l1)
                                        break;
                                else
                                        count++;
                                flag=0;
                               /// i++;
                        }

                        else
                        {
                                while(j<l2&&blue[j]<=red[i])
                                {
                                        j++;
                                }

                                if(j==l2)
                                        break;
                                else
                                        count++;
                                flag=1;
                               // j++;
                        }

                }

                cout<<count<<endl;
        }

        return 0;
}
