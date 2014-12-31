/*
Author: Golam Rahman Tushar
........Aust Cse 27th batch.........
*/

//{ Template

//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;
//}

//}
//{ Floating-points
#define EPS DBL_EPSILON
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define INF 1<<29
#define ll long long
#define db double
#define pii pair<int ,int >
#define NL puts("")
#define G getchar()

template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}
//}

//compute b^p
ll Pow(ll  b,ll  p){
    ll  ret = 1;
    while(p){
        if(p&1) ret *= b ;
        p >>= (1ll) , b *= b ;
    }
    return ret ;
}

//compute b^p%m
ll BigMod(ll  b,ll  p ,ll  m ){
     ll  ret = 1 ;
     while(p)  {
        if(p&1) ret = (ret * b ) % m ;
        p >>= (1ll) , b = (b*b)%m ;
     }
    return ret ;
}

//compute gcd of (a,b)
ll GCD(ll a , ll b){
    while(b) b ^=  a ^= b ^= a %= b ;
    return a;
}

//compute lcm of (a,b)
ll LCM(ll a , ll b) {
     return (a / GCD(a,b)*b);
}

ll power(ll n,ll m)
{
    ll ans=1,p=n;
    while(m)
    {
        if(m&1) ans*=p;
        p*=p;
        m=m>>1;
    }
    return ans;
}


int main ()
{
        int i, prnt[30];
        char str[30];
        map<char,int>m;
        m['A']=0,m['E']=m['I']=m['O']=m['U']=m['Y']=m['W']=m['H']= 0;
        m['B']=m['F']=m['P']=m['V']=1;
        m['C']=m['G']=m['J']=m['K']=m['Q']=m['S']=m['X']=m['Z']=2;
        m['D']=m['T']=3;
        m['L']=4;
        m['M']=m['N']=5;
        m['R']=6;

        printf("         NAME                     SOUNDEX CODE\n");

        while(scanf("%s",str)!=EOF)
        {
                memset(prnt, 0, sizeof(prnt));
                printf("         %s",str);
                int l = strlen(str);

                for(i=0;i<(25-l);i++) printf(" ");
                printf("%c",str[0]);
                int j = 1;
                for(i=1;i<l&&j<4;i++)
                {
                        if(m[str[i]]!=m[str[i-1]]&&m[str[i]]) prnt[j++] = m[str[i]];
                }

                for(i=1;i<=3;i++) printf("%d",prnt[i]);
                printf("\n");
        }

        printf("                   END OF OUTPUT\n");
        return 0;
}
