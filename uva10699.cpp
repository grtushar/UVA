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

#define INF 1<<29
#define ll long long
#define N 1007

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

void sieve()
{
        int i,j,sq=sqrt(N);
        prime[0]=prime[1]=true;

        primes.push_back(2);

        for(i=4;i<N;i+=2) prime[i]=true;

        for(i=3;i<=sq;i+=2) {
                if(prime[i]==false) {
                        primes.push_back(i);
                        for(j=i*i;j<N;j+=2*i)
                                prime[j]=true;
                }
        }

        while(i<N)
        {
                if(prime[i]==false) primes.push_back(i);
                i+=2;
        }
}

int count_pf(int n) {
    int i, cnt = 0;
    for(i=0;primes[i]<=sqrt(n);i++) {
        if(n%primes[i]==0) {
            cnt++;
            while(n%primes[i]==0) n/=primes[i];
        }
    }

    if(n>1) cnt++;
    return cnt;
}

int main ()
{
    freopen("input.txt","r",stdin);
    sieve();
    int n;
    while(scanf("%d",&n)&&n) {
        cout<<n<<" : "<<count_pf(n)<<endl;
    }
    return 0;
}
