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

ll fact[13];

void factorial()
{
        int i;
        fact[0] = 1;
        for(i=1;i<=12;i++)
        {
                fact[i] = fact[i-1]*i;
        }
}

int main ()
{
        //factorial();
        int b[10],x,i,n,sum,ans,carry;
        ll cmb;

        while(scanf("%d",&n)&&n)
        {
                memset(b,0,sizeof(b));
                for(i=0;i<n;i++)
                {
                        scanf("%d",&x);
                        b[x]++;
                }

                /*cmb = fact[n];
                for(i=0;i<=9;i++) cmb/=b[i];*/

                sum=0;
                for(i=0;i<9;i++)
                {
                        sum+=(b[i]*i);
                }

                cout<<sum<<endl;

                carry = ans = 0;
                ll lol = 1;
                for(i=0;i<n;i++)
                {
                        ans+=((sum+carry)%10)*lol;
                        carry = (sum+carry)/10;
                        lol*=10;
                }

                if(sum>9) ans+=carry;

                cout<<ans<<endl;
        }
        return 0;
}
