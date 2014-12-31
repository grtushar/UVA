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
//}

template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}

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
int GCD(int a , int b){
    while(b) b ^=  a ^= b ^= a %= b ;
    return a;
}

//compute lcm of (a,b)
ll LCM(ll a , ll b) {
     return (a / GCD(a,b)*b);
}

ll power(int n,int m)
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
bool rep(ll x)
{
    if(x<10) return false;
    ll i,j,repz;
    stringstream ss;
    ss<<x;
    string str = ss.str();
    ll l = str.size();

    for(repz=1;repz<=l/2;repz++)
    {
        i=0,j=repz;
        while(j<l&&str[i]==str[j])
        {
            i++; j++;
            if(i>=repz)
            {
                i=0;
            }
        }

        if(i==0&&j>=l) return true;
    }

    return false;
}

//void pre_rep_cal()
//{
//        for(k=2;k<=18;k++)
//        {
//                for(i=1;i<=k/2;i++)
//                {
//                        if(k%i==0)
//                        {
//
//                        }
//                }
//        }
//}
int main()
{
        for(int i=1;i<=100000;i++)
        {
                if(rep(i)) cout<<i<<endl;
        }
            ll t,n,i;
            scanf("%lld",&t);

            while(t--)
            {
                scanf("%lld",&n);

                if(n%10==0)
                {
                        printf("%lld%lld\n",n,n);
                        continue;
                }

                for(i=n;;i+=n)
                {
                    if(rep(i))
                    {
                        printf("%lld\n",i);
                        break;
                    }
                }

            }
            return 0;
}
