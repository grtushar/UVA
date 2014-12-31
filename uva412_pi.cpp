using namespace std;

#include<iostream>
#include<cmath>
#include<cstdio>

int GCD(int a,int b)
{
    if(b==0)
        return a;
    else
        return GCD(b,a%b);
}


int main()
{
    int t,arr[55],i,j,k,cnt,temp;
    double ans;

    while(cin>>t&&t)
    {
        cnt=0;
        for(i=0;i<t;i++)
            cin>>arr[i];

        for(j=0;j<t-1;j++)
        {
            for(k=j+1;k<t;k++)
            {
                if(GCD(arr[j],arr[k])==1)
                    cnt++;
            }
        }
        temp = (t*(t-1))/2;

        if(cnt==0)
            cout<<"No estimate for this data set."<<endl;
        else
        {
            ans = sqrt((6.0*(double)temp)/(double)cnt);
            printf("%.6lf\n",ans);
        }
    }
    return 0;
}
