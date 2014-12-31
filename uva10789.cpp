using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

#define N 2010

bool prime[N];

void sieve()
{
    memset(prime,true,sizeof(prime));

    prime[0]=prime[1]=false;

    int i,j,sqrtN = int( sqrt( N ) );

    for( i = 2; i <= sqrtN; i += 1 )
        if( prime[i]) //0 means i is a prime
           for( j = 2*i; j <= N; j += i )
              prime[j] = false;  //cut the multiples

}

int main()
{
    int T,count[150],i,l,Case=1;
    string str;
    bool flag;
    sieve();
    scanf("%d",&T);

    while(T--)
    {
        flag=true;
        for(i=47;i<125;i++)
            count[i]=0;

        cin>>str;
        l=str.length();

        for(i=0;i<l;i++)
        {
            count[str[i]]++;
        }

        printf("Case %d: ",Case++);

        for(i=47;i<124;i++)
        {
            if(prime[count[i]])
            {
                printf("%c",i);
                flag=false;
            }
        }

        if(flag)
            cout<<"empty";

        cout<<endl;
    }

    return 0;
}
