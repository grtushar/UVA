#include<iostream>

using namespace std;

int main()
{
    long long int a,b,c;
    while(cin>>a>>b>>c&&(a||b||c))
    {
        if(a<b<c||b<a<c)
        {
            if(a*a+b*b==c*c)
                cout<<"right"<<endl;
            else
                cout<<"wrong"<<endl;
        }

        else if(a<c<b||c<a<b)
        {
            if(a*a+c*c==b*b)
                cout<<"right"<<endl;
            else
                cout<<"wrong"<<endl;
        }

      else
        {
            if(b*b+c*c==a)
                cout<<"right"<<endl;
            else
                cout<<"wrong"<<endl;
        }

    }
    return 0;
}
