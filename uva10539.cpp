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
#define INF (1<<29)
#define ll long long
#define CountOne(mask) __builtin_popcountll(mask)
#define N 1000007

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
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

bool isVowel(char ch){ch=tolower(ch);if(ch=='a' | ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}

///int dx[]= {-1,-1,0,0,1,1};
///int dy[]= {-1,0,-1,1,0,1};
///int dx[]= {0,0,1,-1};/*4 side move*/
///int dy[]= {-1,1,0,0};/*4 side move*/
///int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
///int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
/*................Code Starts Here................*/

bool prime[N];
vector<ll>primes;
const long long int mx = 1000000000000LL;

void sieve() {
        ll i,j,sq=sqrt(N);
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

int main() {
    //freopen("input.txt","r",stdin);
    sieve();
    vector<ll>ans;
    int t;
    ll a, b, i, sz = primes.size(), j;
    for(i=0;i<sz;i++) for(j=primes[i]*primes[i];j<mx;j*=primes[i]) ans.push_back(j);

    sort(ans.begin(), ans.end());
    unique(ans.begin(), ans.end());

    scanf("%d",&t);
    while(t--) {
        scanf("%lld %lld",&a, &b);
        printf("%d\n",upper_bound(ans.begin(), ans.end(), b) - lower_bound(ans.begin(), ans.end(), a));
    }
    return 0;
}
