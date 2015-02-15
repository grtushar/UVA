#include<iostream>

using namespace std;

long long int factorial(long long int n)
{
    long long int result=1;
    for(long long int i=n;i>0;i--)
    result=result*i;
    return result;
}

int main()
{
    long long int N,B,res,c,num,l,count,k,count2;
    string str;
    while(cin>>N>>B)
    {
        count=0;
        count2=0;
        num=0;
        c=1;
        res=factorial(N);

        while(res)
        {
            num=num+((res%B)*c);
            res=res/B;
            c=c*10;
        }
        k=num;
        while(k)
        {
            if(k%10==0)
            count++;
            k=k/10;
            count2++;
        }
        cout<<count<<" "<<count2<<endl;
    }
    return 0;
}
