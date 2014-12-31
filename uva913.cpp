using namespace std;

#include<iostream>

int main()
{
        long long int n;

        while(cin>>n)
        {
                n=(n+1)/2;
                cout<<3*((2*n*n)-1)-6<<endl;
        }

        return 0;
}
