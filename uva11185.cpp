using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define ld long long int

int main()
{
    int i,arr[1000];
    ld n;

    while(cin>>n&&n>=0)
    {
        if(n==0)
            cout<<0<<endl;
        else
        {
            i=0;
            while(n)
            {
                arr[i++]=n%3;
                n/=3;
            }

            i--;
            while(i>=0)
            {
                cout<<arr[i];
                i--;
            }

            cout<<endl;
        }

    }

    return 0;
}
