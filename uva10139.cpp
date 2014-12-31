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

#define N 50000
vector<ll>primes;
bool prime[N];

void sieve()
{
        int i,j,sqr = sqrt(N);
        prime[0]=prime[1]=true;

        primes.push_back(2);
        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<sqr;i+=2)
        {
                if(prime[i]==false)
                {
                        primes.push_back(i);
                        for(j=i*i;j<N;j+=2*i)
                                prime[j]=true;
                }
        }

        while(i<N)
        {
                if(prime[i]==false)
                        primes.push_back(i);
                i+=2;
        }
}

bool ache(ll p, ll fn, ll cnt)
{
        ll ans = fn/p, temp=p;
        if(ans>=cnt) return true;

        ll no3=1;
        while(temp*p<=fn)
        {
                temp*=p;
                ans += no3;
                if(ans>=cnt) return true;
                no3++;
        }

        return false;
}


int main ()
{
        sieve();
        ll n, m, tempm, sz = primes.size(), j, cnt;;

        while(scanf("%lld %lld",&n, &m)==2)
        {
                tempm = m;
                bool flag = true;
                for(j=0;flag&&j<sz&&primes[j]<=sqrt(m);j++)
                {
                        if(m%primes[j]==0)
                        {
                                cnt = 0;
                                while(m%primes[j]==0)
                                {
                                        m/=primes[j];
                                        cnt++;
                                }

                                if(!ache(primes[j],n,cnt)){
                                        flag = false;
                                        break;
                                }
                        }

                        if(m==1) break;
                }

                if(flag&&m>1)
                {
                        if(!ache(m,n,1)){
                                flag = false;
                        }
                }

                if(flag)
                        printf("%lld divides %lld!\n",tempm,n);
                else
                        printf("%lld does not divide %lld!\n",tempm,n);
        }
        return 0;
}
