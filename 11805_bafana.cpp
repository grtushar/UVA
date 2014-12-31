#include<iostream>

using namespace std;

int main()
{
    long long int T,N,K,P,count=1,ans;
    cin>>T;

    while(T--)
    {
        cin>>N>>K>>P;
        if(K+P<=N)
        ans=K+P;
        else
        {
            ans=K+P-N;
            while(ans>N)
            ans-=N;
        }
        cout<<"Case "<<count++<<": "<<ans<<endl;

    }
    return 0;
}
