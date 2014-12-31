#include<iostream>

using namespace std;

int main()
{
    long long int n,p,temp;
    while((cin>>n))
    {
        p=1;
        temp=0;
        while(p<n)
        {
             if(temp)
            {
                p*=2;
                temp=0;
            }
            else
            {
                p*=9;
                temp=1;
            }
        }
        if(temp)
        cout<<"Stan wins."<<endl;
        else
        cout<<"Ollie wins."<<endl;
    }
    return 0;
}
