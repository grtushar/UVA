// confused about it (so skipped)

using namespace std;

#include<iostream>

int main()
{
    int n;
    while(cin>>n&&n>0)
    {
        cout<<((n*(n-1))/2)-n<<endl;
    }

    return 0;
}
