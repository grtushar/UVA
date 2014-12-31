using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

typedef long long int ll_d;

int main()
{
        string str1,str2;
        ll_d l1,l2,i,j;

        while(cin>>str1>>str2)
        {
                l1=str1.length();
                l2=str2.length();

                bool flag=true;

                for(i=0,j=0;i<l1;i++)
                {
                        while(j<l2&&str1[i]!=str2[j])
                                j++;
                        if(j==l2)
                        {
                                flag=false;
                                break;
                        }
                        j++;
                }

                if(flag)
                        cout<<"Yes"<<endl;
                else
                        cout<<"No"<<endl;
        }

        return 0;
}
