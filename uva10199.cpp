#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1LL<<31-1
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

vector <int> adj[1000];
set <string> s;
map<int,string>  mapin2s;
map<string,int>  maps2in;
int back[100+10],discovery[100+10],cnt,seq;//,child[10000+10];
bool visited[100+10],art_point[100+10];
void dfs(int u)
{
        int child=0;
        visited[u]=true;
        back[u]=discovery[u]=++seq;

        for(int i=0;i<adj[u].size();i++)
        {
                int v = adj[u][i];
                if(visited[v]==false)
                {
                        dfs(v);
                        child++;
                        back[u]=min(back[u],back[v]);
                       if(discovery[u]>1 && back[v]>=discovery[u] && !art_point[u]) { art_point[u]=1;
                                        s.insert(mapin2s[u]);//cnt++;
                       }

                }
                else if(discovery[v]<discovery[u]-1) // back edge
                        back[u]=min(discovery[v],back[u]);
        }
          if(discovery[u]==1  && child>=2 && !art_point[u]) {
                                    art_point[u]=1;
                                    s.insert(mapin2s[u]);//cnt++;
          }

}



int main()
{

    //freopen("in.txt", "r", stdin);
    int n,ct=0;
    while(sc(n) && n)
    {
           int i,m;
           if(ct) puts("");
           string a,b;
           rep(i,110) adj[i].clear();
           maps2in.clear();
           mapin2s.clear();
           s.clear();

           memo(art_point,0);
           rep(i,n)
           {
                  cin>>a;
                  maps2in[a]=i+1;
                  mapin2s[i+1]=a;
           }
           cin>>m;
           rep(i,m)
           {
                  cin>>a>>b;
                  adj[maps2in[a]].pb(maps2in[b]);
                   adj[maps2in[b]].pb(maps2in[a]);
           }
           FOR(i,1,n)
           {
           memo(discovery,0);
           memo(back,0);
           memo(visited,0);
           memo(art_point,0);
           seq=0;
           if(!visited[i])
           dfs(i);

           }
           //sort(ans.begin(),ans.end());
           printf("City map #%d: %d camera(s) found\n",++ct,s.size());
           for( set<string> :: iterator it=s.begin();it!=s.end();it++)
           {
                  cout<<(*it)<<endl;
           }
    }


}

/*#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>=(b)? (a) : (b))
int a[1005],dp[1005];
int Dp(int pos,int end)
{
       if(pos>end) return 0;
       if(dp[pos]!=-1) return dp[pos];
       dp[pos]=max(Dp(pos+2,end)+a[pos],Dp(pos+1,end));
       return dp[pos];
}
int main()
{
       int t,cs,n,i;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {     scanf("%d",&n);
             for(i=0;i<n;i++) scanf("%d",&a[i]);
              memset(dp,-1,sizeof(dp));
              int ans=Dp(0,n-2);
              memset(dp,-1,sizeof(dp));
              ans=max(Dp(1,n-1),ans);
              printf("Case %d: %d\n",cs,ans);

       }
}


*/












/*#include <stdio.h>
#include <string.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++)
    {
        char str1[50],str2[50];
        long long int y1,y2,count=0;
        int d1,d2;

        scanf("%s %d, %lld",str1,&d1,&y1);
        scanf("%s %d, %lld",str2,&d2,&y2);

         count=((y2/4)-(y2/100)+(y2/400))-((y1/4)-(y1/100)+(y1/400));

        if( ((y1%4==0 && y1%100!=0) || y1%400==0) &&(strcmp(str1,"January")==0 || strcmp(str1,"February")==0))
        count+=1;

        if( ((y2%4==0 && y2%100!=0) || y2%400==0) &&((strcmp(str2,"January")==0 || strcmp(str2,"February")==0) && d1<29))
        count-=1;

       if(y1==y2)
       {
        if((strcmp(str1,"January")==0 || strcmp(str1,"February")==0 ))
         if((strcmp(str2,"January")!=0 && strcmp(str2,"February")!=0) || (strcmp(str2,"February")==0 && d2==29))
            if((y1%4==0 && y1%100!=0) || y1%400==0)
            count=1;
       }


         printf("Case %d: %lld\n",i,count);
    }
    return 0;

}
*/
