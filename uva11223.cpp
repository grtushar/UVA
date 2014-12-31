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
        map<string, char>m;
        m[".-"]='A';
	m["-..."]='B';
	m["-.-."]='C';
	m["-.."]='D';
	m["."]='E';
	m["..-."]='F';
	m["--."]='G';
	m["...."]='H';
	m[".."]='I';
	m[".---"]='J';
	m["-.-"]='K';
	m[".-.."]='L';
	m["--"]='M';
	m["-."]='N';
	m["---"]='O';
	m[".--."]='P';
	m["--.-"]='Q';
	m[".-."]='R';
	m["..."]='S';
	m["-"]='T';
	m["..-"]='U';
	m["...-"]='V';
	m[".--"]='W';
	m["-..-"]='X';
	m["-.--"]='Y';
	m["--.."]='Z';
	m["-----"]='0';
	m[".----"]='1';
	m["..---"]='2';
	m["...--"]='3';
	m["....-"]='4';
	m["....."]='5';
	m["-...."]='6';
	m["--..."]='7';
	m["---.."]='8';
	m["----."]='9';
	m[".-.-.-"]='.';
	m["--..--"]=',';
	m["..--.."]='?';
	m[".----."]='\'';
	m["-.-.--"]='!';
	m["-..-."]='/';
	m["-.--."]='(';
	m["-.--.-"]=')';
	m[".-..."]='&';
	m["---..."]=':';
	m["-.-.-."]=';';
	m["-...-"]='=';
	m[".-.-."]='+';
	m["-....-"]='-';
	m["..--.-"]='_';
	m[".-..-."]='\"';
	m[".--.-."]='@';

	int t, i, Case = 1;
	scanf("%d",&t);
	getchar();

	while(t--)
        {
                string str;
                getline(cin,str);
                string temps = "";
                int l = str.length();

                if(str[l-1]!=' ') { str+=' '; l++; }
                printf("Message #%d\n",Case++);
                for(i=0;i<l;i++)
                {
                        if(i>0&&str[i-1]==' '&&str[i]==' ')
                        {
                                printf(" ");
                        }
                        else if(str[i]==' ')
                        {
                                printf("%c",m[temps]);
                                temps = "";
                        }
                        else
                                temps += str[i];
                }

                cout<<endl;
                if(t) cout<<endl;
        }
        return 0;
}
