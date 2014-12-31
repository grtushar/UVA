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

#define INF (1<<29)
#define ll long long
#define N 10007

template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}
//}

template <class T> T gcd(T a,T b){if(b==0) return a;else return gcd(b,a%b);}
template <class T> T lcm(T a,T b){return (a*b)/gcd(a,b);}
template <class T> T power( T a, T b){if(b==0) return 1; T x=a;for(T i=2;i<=b;i++) a=a*x;return a;}
template <class T> T BigMod(T a,T b,T c){if(a==0) return 0;if(b==0) return 1;if(b%2==0){T x=BigMod(a,b/2,c)%c;return (x*x)%c;}else return  ((a%c)*BigMod(a,b-1,c)%c)%c;}

bool prime[N];
vector<int>primes;
int sz, fact[10007][10007];

bool prime[N];
vector<int>primes;

void sieve() {
        int i,j,sq=sqrt(N);
        prime[0]=prime[1]=true; primes.push_back(2);

        for(i=4;i<N;i+=2) prime[i]=true;
        for(i=3;i<=sq;i+=2) {
            if(prime[i]==false) {
                primes.push_back(i);
                for(j=i*i;j<N;j+=2*i) prime[j]=true;
            }
        }
        while(i<N) {
            if(prime[i]==false) primes.push_back(i);
            i+=2;
        }
}

void prime_fact(int x) {
    int temp = x, j;
    for(j=0;j<sz&&primes[j]<=sqrt(x);j++) {
        //fact[temp][primes[j]] = 0;
        if(x%primes[j]==0) {

            while(x%primes[j]==0) {
                fact[temp][primes[j]]++;
                x/=primes[j];
            }
        }
    }

    if(x>1) fact[temp][x] = 1;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    sieve();
    int i, j, t, m, n, Case = 1;
    sz = primes.size();
    for(i=2;i<=10000;i++) {
        prime_fact(i);
        for(j=0;j<sz&&primes[j]<=i;j++) {
            fact[i][primes[j]]+=fact[i-1][primes[j]];
        }
    }
    scanf("%d",&t);

    while(t--) {
        scanf("%d %d",&m,&n);
        int ans = INF;
        for(i=0;i<sz&&primes[i]<=n;i++) {
            int temp = fact[m][primes[i]] - fact[m-1][primes[i]];
            if(temp>0) ans = min(ans,fact[n][primes[i]]-temp);
        }

        if(ans>0&&ans!=INF) printf("Case %d:\n%d\n",Case++,ans+1);
        else printf("Case %d:\nImpossible to divide\n", Case++);
    }
    return 0;
}
