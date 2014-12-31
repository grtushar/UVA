#include<iostream>

using namespace std;

int main()
{
    long long int a,b,c,d,L,count,i;
    while(cin>>a>>b>>c>>d>>L&&(a||b||c||d||L))
    {
        count=0;
        for(i=0;i<=L;i++)
        {
            if((a*(i*i)+(b*i)+c)%d==0)
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
