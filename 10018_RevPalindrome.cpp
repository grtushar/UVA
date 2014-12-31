#include<iostream>

using namespace std;

long long int reverse(long long int x)
{
    long long int res=0;
    while(x)
    {
        res=res*10+x%10;
        x=x/10;
    }
    return res;
}

int main()
{
    long long int T,x,count;
    cin>>T;

    while(T--)
    {
        count=0;
        cin>>x;
        while(x+reverse(x)!=reverse(x+reverse(x)))
        {
            x=x+reverse(x);
            count++;
        }
        cout<<count+1<<" "<<x+reverse(x)<<endl;
    }
    return 0;
}
