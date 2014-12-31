using namespace std;

#include<iostream>

#define abss(x) ((x>0)?(x):(-x))

int main()
{
    int t;
    long long int n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        n*=63;
        n+=7492;
        n*=5;
        n-=498;
        //cout<<n<<endl;
        n=abss(n);

        n/=10;

        n=n%10;

        cout<<n<<endl;
    }

    return 0;
}
