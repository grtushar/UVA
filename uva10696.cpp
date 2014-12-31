using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
    int n;
    while(scanf("%d",&n)&&n>0)
    {
        if(n>=101)
            cout<<"f91("<<n<<") = "<<n-10<<endl;
        else
            cout<<"f91("<<n<<") = 91"<<endl;
    }
    return 0;
}
