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

#define N 1000000+10
bool prime[N];
vector<int>primes;
int divisor[N], result[N];


void sieve()
{
        int i,j,sqr = sqrt(N);
        prime[0]=prime[1]=true;

        primes.push_back(2);
     /*   for(i=4;i<N;i+=2)
                prime[i]=true; */

        for(i=3;i<sqr;i+=2)
        {
                if(prime[i]==false)
                {
                        primes.push_back(i);
                        for(j=i*i;j<=N;j+=2*i)
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

void count_divisor()
{
        int cnt,sqr, ans,i,j,temp,sz = primes.size();
        for(i=1;i<=1000000;i++)
        {
                ans=1;
                temp = i;
                sqr = sqrt(temp);
                for(j=0;j<sz&&primes[j]<=sqr;j++)
                {
                        if(temp%primes[j]==0)
                        {
                                cnt=0;
                                while(temp%primes[j]==0)
                                {
                                        temp/=primes[j];
                                        cnt++;
                                }

                                ans*=cnt+1;
                        }
                }

                if(temp>1) ans*=2;
                divisor[i] = ans;
        }
}

int main () {

        int i,n,t,mx;
        sieve();
        count_divisor();
        result[1]=1;
        for(i=2;i<=1000000;i++){
              if(divisor[i]>=divisor[result[i-1]]) result[i]=i;
              else result[i] = result[i-1];
        }

        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);
                printf("%d\n",result[n]);
        }
        return 0;
}
