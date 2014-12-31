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

#define N 100000
bool prime[N];
vector<ll>primes;

void sieve()
{
        ll i,j,sqr = sqrt(N);
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

//vector<ll>serial;

ll solve(ll n)
{
        if(n==1) return 2;
        //serial.clear();
        ll ans = 0, sz = primes.size(), j, temp;
        bool flag = true;
        for(j = 0; j<sz&&primes[j]<=sqrt(n);j++)
        {
                if(n%primes[j]==0)
                {
                        flag = false;
                        temp=1;
                        while(n%primes[j]==0)
                        {
                                n/=primes[j]; temp*=primes[j];
                        }

                        ans+=temp;
                        //serial.push_back(power(primes[j],cnt));
                }
                if(n==1) break;
        }

        if(n>1) ans+=n;
       // if(flag) ++ans;
        return ans;
}


int main ()
{
        sieve();
        ll n; int Case=1;
        while(scanf("%lld",&n)!=-1&&n)
        {
                ll ans = solve(n);
                if(ans==n) ans++;
                if(n==1) ans=2;
                printf("Case %d: %lld\n",Case++,ans);
        }
        return 0;
}


/*
if(n>1) serial.push_back(n);
        if(flag) serial.push_back(1);

        sort(serial.begin(),serial.end());

        ll a = serial[0], b = 1, szs = serial.size();

        for(j=1;j<szs;j++)
        {
                if((a*serial[j]+b)>(a+b*serial[j])) b*=serial[j];
                else a*=serial[j];
        }
*/
