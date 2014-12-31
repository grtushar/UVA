using namespace std;

#include<iostream>

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int n,i,j;

    while(cin>>n&&n>0)
    {
        int g=0;
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
                g+=gcd(i,j);
        }

        cout<<g<<endl;
    }

    return 0;
}
