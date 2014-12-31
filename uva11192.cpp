using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

int main()
{
    int n,i,j,k;
    char str[110],temp;

    while(cin>>n&&n>0)
    {
        scanf(" %s",str);

        int l = strlen(str);
        n=l/n;

        for(i=0;i<l;i+=n)
        {
            k=i+n-1;
            for(j=i;j<i+n/2;j++)
            {
                temp = str[j];
                str[j] = str[k];
                str[k] = temp;
                k--;
            }
        }

        for(i=0;i<l;i++)
            cout<<str[i];

        cout<<endl;
    }

    return 0;
}
