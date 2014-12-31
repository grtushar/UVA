using namespace std;

#include<iostream>
#include<cmath>

long long int cube(long long int a)
{
    return a*a*a;
}

int main()
{
    int i,a,b,c;
    for(i=6;i<=200;i++)
    {
        for(a=2;a<i;a++)
        {
            for(b=a+1;b<i;b++)
            {
                for(c=b+1;c<i;c++)
                {
                    if(cube(i)==cube(a)+cube(b)+cube(c))
                        cout<<"Cube = "<<i<<", Triple = ("<<a<<","<<b<<","<<c<<")"<<endl;
                }
            }
        }
    }

    return 0;
}
