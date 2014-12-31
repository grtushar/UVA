using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define n 1000005

int prime[n];

long long int arr[n],k,i,j;

void primeFIND()
{

    k=0;

    memset(prime , 0 , sizeof prime);

    prime[0]=prime[1]=1;

    for(i=2;i<=n;i++)
    {
        if(!prime[i])
        {
            for(j=i*i;j<=n;j=j+i)
                prime[j]=1;
            arr[k++]=i;
        }
    }

}

int main()
{
    long long int N,x,rev;

    primeFIND();

    while(cin>>N)
    {
        rev = 0;
        x = N;


        while(x)
        {
            rev = rev*10+(x%10);
            x/=10;
        }

        if(!prime[N]&&!prime[rev]&&N!=rev)
            cout<<N<<" is emirp."<<endl;
        else if(!prime[N])
            cout<<N<<" is prime."<<endl;
        else
            cout<<N<<" is not prime."<<endl;
    }
    return 0;
}
