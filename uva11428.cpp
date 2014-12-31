using namespace std;

#include<iostream>
#include<cmath>

int main()
{
    int n,i,j;

    while(cin>>n&&n>0)
    {
        int sq=(int)sqrt(n);
        bool flag=false;
        for(i=2;i<=sq;i++)
        {
            for(j=1;j<i;j++)
            {
                if(pow(i,3)-pow(j,3)==n)
                {
                    flag=true;
                    break;
                }
            }

            if(flag)
                break;
        }

        if(flag)
            cout<<i<<" "<<j<<endl;
        else
            cout<<"No solution"<<endl;
    }

    return 0;
}
