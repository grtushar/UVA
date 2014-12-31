/*using namespace std;

#include<iostream>
#include<cmath>
#include<cstdio>

#define pi 3.141592653589793

int main()
{
    double a,b,c,area1,area2,area3;

    while(scanf("%lf%lf%lf",&a,&b,&c)==3)
    {
        double s = (a+b+c)/2.0;

        area2=sqrt(s*(s-a)*(s-b)*(s-c));
        area3=pi*pow((area2/s),2);//*(area2/s);

        area1=(pi*pow(((a*b*c)/(4*area2)),2))-area2;
        area2=area2-area3;

        printf("%.4lf %.4lf %.4lf\n",area1,area2,area3);
    }

    return 0;
}*/

#include <map>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;
char inp[100000+5];
string shuffle(string s)
{
    int l = s.size();
    if( l <= 3 )return s;

    sort(s.begin()+1,s.end()-1);
    return s;
}

int main()
{
    int t,n,i,cs=1,Q;
    string s,inss;

    map< string , int >dictionary;
    scanf("%d",&t);
    while(t--)
    {

        dictionary.clear();

        scanf("%d",&n);
        for( i = 0 ; i < n ; i++ ){
                cin>>inss;
                dictionary[ shuffle(inss)  ]++;
        }
        printf("Case %d:\n",cs++);
        scanf("%d ",&Q);
        while(Q--)
        {
                gets(inp);
                int ret = 1;
                int len = strlen(inp);
                s="";
                for( i = 0 ; i < len ; i++ ){
                        if( inp[i] == ' '){
                            ret *= dictionary[ shuffle(s) ];
                            s="";
                        }
                        else s += inp[i];
                }
                ret *= dictionary[shuffle(s)];
                printf("%d\n",ret);
        }
    }
}
