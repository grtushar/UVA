using namespace std;

#include<iostream>
#include<cstdio>

int s,t,n;

void line()
{
    int l=(s*n)+(n+1)*t;

    for(int i=0;i<t;i++)
    {
        for(int j=0;j<l;j++)
            cout<<"*";
        cout<<endl;
    }

}

void grid()
{
    for ( int i = 0; i < s; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            for ( int k = 0; k < t; k++ )
                cout<<"*";
            for ( int k = 0; k < s; k++ )
                cout<<".";
        }

        for ( int k = 0; k < t; k++ )
            cout<<"*";
        cout<<endl;
    }
}

int main()
{
    int Case=1;
    while(cin>>s>>t>>n)
    {
        if(s==0&&t==0&&n==0)
            break;
        cout<<"Case "<<Case++<<":"<<endl;
        for(int i=0;i<n;i++)
        {
            line();
            grid();
        }

        line();

        cout<<endl;
    }

    return 0;
}
