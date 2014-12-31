using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>

int main()
{
    int T,L;
    double r,ca,aa,pi = acos(-1);
    cin>>T;

    while(T--)
    {
        cin>>L;
        r = (double)L/5.0;
        ca = pi*(r*r);
        aa = (L*(L/(double)(5.0/3.0)));

        printf("%.2lf %.2lf\n",ca,aa-ca);
    }
    return 0;
}
