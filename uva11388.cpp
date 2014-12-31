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

int power(int n,int m)
{
    int ans=1,p=n;
    while(m)
    {
        if(m&1) ans*=p;
        p*=p;
        m=m>>1;
    }
    return ans;
}

#define N 50000
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

int solve(int g, int l)
{
        map<int,int>m;
        int sz = primes.size(),j,cnt,b = 1;
        for(j=0;j<sz&&primes[j]<=sqrt(g);j++)
        {
                if(g%primes[j]==0)
                {
                        cnt = 0;
                        while(g%primes[j]==0)
                        {
                                g/=primes[j]; cnt++;
                        }

                        m[primes[j]]=cnt;

                }

                if(g==1) break;
        }

        if(g>1) m[g] = 1;

        for(j=0;j<sz&&primes[j]<=sqrt(g);j++)
        {
                if(l%primes[j]==0)
                {
                        cnt = 0;
                        int temp = 1;
                        while(l%primes[j]==0)
                        {
                                l/=primes[j]; cnt++;
                                temp*=primes[j];
                        }

                       b = power(primes[j],max(cnt,m[primes[j]]));
                }

                if(l==1) break;
        }

        if(l>1&&m[l]==0) b*=l;

        return b;
}

int main()
{
        sieve();
        int g, l, a, b, t;

        scanf("%d",&t);
        while(t--)
        {
                scanf("%d %d",&g,&l);
                a = g;
                b = solve(g,l);

                //cout<<a<<" "<<b<<endl;

                if(GCD(a,b)==g&&LCM(a,b)==l)
                        printf("%d %d\n",a,b);
                else printf("-1\n");
        }

        return 0;
}
