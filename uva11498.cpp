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
        int q, sx, sy, x, y;

        while(scanf("%d",&q)==1&&q)
        {
                scanf("%d %d", &sx, &sy);

                while(q--)
                {
                        scanf("%d %d",&x, &y);
                        if(x==sx||y==sy) printf("divisa\n");
                        else if(x>sx&&y>sy) printf("NE\n");
                        else if(x>sx&&y<sy) printf("SE\n");
                        else if(x<sx&&y>sy) printf("NO\n");
                        else printf("SO\n");
                }
        }
        return 0;
}

/*
 if(sx<0&&sy<0)
                {
                        while(q--)
                        {
                                scanf("%d %d",&x, &y);
                                if(x==sx||y==sy)
                                {
                                        printf("divisa\n");
                                        continue;
                                }

                                if(x>sx&&y>sy) printf("NE\n");
                                else if(x>sx&&y<sy) printf("SE\n");
                                else if(x<sx&&y>sy) printf("NO\n");
                                else  printf("SO\n");
                        }
                }
                else if(sx<0&&sy>0)
                {
                        while(q--)
                        {
                                scanf("%d %d",&x, &y);
                                if(x==sx||y==sy)
                                {
                                        printf("divisa\n");
                                        continue;
                                }

                                if(x>sx&&y>sy) printf("NE\n");
                                else if(x>sx&&y<sy) printf("SE\n");
                                else if(x<sx&&y>sy) printf("NO\n");
                                else printf("SO\n");
                        }
                }
                else if(sx>0&&sy<0)
                {
                        while(q--)
                        {
                                scanf("%d %d",&x, &y);
                                if(x==sx||y==sy)
                                {
                                        printf("divisa\n");
                                        continue;
                                }

                                if(x>sx&&y>sy) printf("NE\n");
                                else if(x>sx&&y<sy) printf("SE\n");
                                else if(x<sx&&y>sy) printf("NO\n");
                                else printf("SO\n");
                        }
                }
                else if(sx>0&&sy>0)
                {
                        while(q--)
                        {
                                scanf("%d %d",&x, &y);
                                if(x==sx||y==sy)
                                {
                                        printf("divisa\n");
                                        continue;
                                }

                                if(x>sx&&y>sy) printf("NE\n");
                                else if(x>sx&&y<sy) printf("SE\n");
                                else if(x<sx&&y>sy) printf("NO\n");
                                else printf("SO\n");
                        }
                }
*/
