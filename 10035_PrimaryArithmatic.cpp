
using namespace std;
#include<iostream>
int main()
{
    long long unsigned m,n,carry,count;
    while (cin>>m>>n)
    {
          count=0,carry=0;
          if(m==0&&n==0)
          break;

          while (m|| n)
          {
                carry=m%10+n%10+carry;
                if(carry>9)
                 count++;
                carry/=10;
                m/=10;
                n/=10;
          }
          if ( count)
          {
               if( count==1)
               cout<<"1 carry operation."<<endl;
               else
               cout<<count<<" carry operations."<<endl;
          }
          else
          cout<<"No carry operation."<<endl;
    }
    return 0;
}

#include<iostream>

using namespace std;

int main()
{
    long long unsigned int a,b,count,flag;

    while(cin>>a>>b)
    {
        if(a==0&&b==0)
        break;
        count=0;
        flag=0;
        while(a||b)
        {
            flag=(a%10+b%10)+flag;
            if(flag>9)
            count++;
            a=a/10;
            b=b/10;
            flag=flag/10;
        }
      if(count)
         cout<<count<<" carry operations."<<endl;
        else
            cout<<"No carry operation."<<endl;

    }
    return 0;
}
 /*if(!count)
            cout<<"No carry operation."<<endl;
        else if(count==1)
            cout<<"1 carry operation."<<endl;
        else
            cout<<count<<" carry operations."<<endl;*/
