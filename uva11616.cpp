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

map<string, int>ms;
map<int, string>mi;

void initialize()
{
        ms["I"]=1;
	ms["II"]=2;
	ms["III"]=3;
	ms["IV"]=4;
	ms["V"]=5;
	ms["VI"]=6;
	ms["VII"]=7;
	ms["VIII"]=8;
	ms["IX"]=9;
	ms["X"]=10;
	ms["XX"]=20;
	ms["XXX"]=30;
	ms["XL"]=40;
	ms["L"]=50;
	ms["LX"]=60;
	ms["LXX"]=70;
	ms["LXXX"]=80;
	ms["XC"]=90;
	ms["C"]=100;
	ms["CC"]=200;
	ms["CCC"]=300;
	ms["CD"]=400;
	ms["D"]=500;
	ms["DC"]=600;
	ms["DCC"]=700;
	ms["DCCC"]=800;
	ms["CM"]=900;
	ms["M"]=1000;
	ms["MM"]=2000;
	ms["MMM"]=3000;
	mi[1]="I";
	mi[2]="II";
	mi[3]="III";
	mi[4]="IV";
	mi[5]="V";
	mi[6]="VI";
	mi[7]="VII";
	mi[8]="VIII";
	mi[9]="IX";
	mi[10]="X";
	mi[20]="XX";
	mi[30]="XXX";
	mi[40]="XL";
	mi[50]="L";
	mi[60]="LX";
	mi[70]="LXX";
	mi[80]="LXXX";
	mi[90]="XC";
	mi[100]="C";
	mi[200]="CC";
	mi[300]="CCC";
	mi[400]="CD";
	mi[500]="D";
	mi[600]="DC";
	mi[700]="DCC";
	mi[800]="DCCC";
	mi[900]="CM";
	mi[1000]="M";
	mi[2000]="MM";
	mi[3000]="MMM";
}
int main ()
{
        initialize();

        string str;
        int i, temp, j, ans;
        while(cin>>str)
        {
                int l = str.size();
                if(str[0]>='0'&&str[0]<='9')
                {
                        for(i=0;i<l;i++)
                        {
                                temp = str[i]-48;
                                for(int k=i+1;k<l;k++) temp*=10;
                                cout<<mi[temp];
                        }

                        cout<<endl;
                }

                else
                {
                        ans = 0;
                        for(i=0;i<l;i++)
                        {
                                for(j=l;j>i;j--)
                                {
                                        if(i+1==j)
                                        {
                                                string tmp2 = "";
                                                tmp2+=str[i];
                                                //cout<<"temp2 :: "<<tmp2<<endl;
                                                ans+=ms[tmp2];
                                                continue;
                                        }
                                        string tmp = "";//str.substr(i,j);
                                        for(int k=i;k<j;k++) tmp+=str[k];
                                        //cout<<i<<" : "<<j<<" "<<"old temp :: "<<tmp<<endl;
                                        if(ms[tmp])
                                        {
                                                //cout<<"temp :: "<<tmp<<endl;
                                                ans+=ms[tmp];
                                                i=j-1;
                                                tmp.clear();
                                                break;
                                        }
                                        tmp.clear();
                                }
                        }

                        cout<<ans<<endl;
                }
        }
        return 0;
}
