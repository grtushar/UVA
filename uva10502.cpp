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


int main () {
        int i,j,m,n,g,h,x,y,cnt;
        char place[102][102];

        while(cin>>n)
        {
                if(n==0) break;
                cin>>m;
                cnt=0;

                for(i=0;i<n;i++) scanf("%s",place[i]);

                for(i=0;i<n;i++)
                {
                        for(j=0;j<m;j++)
                        {
                                if(place[i][j]=='1')
                                {
                                        cnt++;
                                        x=i+1; y=j+1;

                                        while(y<m&&place[i][y]=='1') { cnt++; y++; }
                                        while(x<n&&place[x][j]=='1') { cnt++; x++; }
                                        //cout<<cnt<<endl;

                                        for(g=i+1;g<x;g++)
                                        {
                                                for(h=j+1;h<y;h++)
                                                {
                                                        if(place[g][h]=='1') cnt++;
                                                        else break;
                                                }
                                                y=h;
                                                if(y==j+1) break;
                                        }

                                        //cout<<"ans:  "<<cnt<<endl;
                                }
                        }
                }

                cout<<cnt<<endl;
        }
        return 0;
}
