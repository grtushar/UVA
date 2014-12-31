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

struct info{
        string str;
        int cnt;
}DNA[102];

bool cmp(info a, info b)
{
        return a.cnt<b.cnt;
}

int main () {

        int t,i,k,l,cnt,n,m;
        scanf("%d",&t);

        bool newline = false;
        while(t--)
        {
                scanf("%d %d",&n,&m);
                for(i=0;i<m;i++){
                        cin>>DNA[i].str;
                }

                 for(i=0;i<m;i++){
                        cnt=0;
                        for(k=0;DNA[i].str[k];k++)
                        {
                                for(l=k+1;DNA[i].str[l];l++) if(DNA[i].str[k]>DNA[i].str[l]) cnt++;
                                DNA[i].cnt=cnt;
                        }
                }
                if(newline) cout<<endl;
                newline = true;

                stable_sort(DNA,DNA+m,cmp);

                for(i=0;i<m;i++) cout<<DNA[i].str<<endl;
        }

        return 0;
}
