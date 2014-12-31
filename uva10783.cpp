using namespace std;

#include<iostream>

int main()
{
    int t,a,b,ans,Case=1;
    cin>>t;

    while(t--)
    {
        cin>>a>>b;

        ans=0;
        for(int i=a;i<=b;i++)
        {
            if(i%2)
                ans+=i;
        }

        cout<<"Case "<<Case++<<": "<<ans<<endl;
    }

    return 0;
}
