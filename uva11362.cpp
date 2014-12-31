using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define mini(a,b) ((a<b)?(a):(b))

bool check(string a,string b)
{
        int l = mini(a.size(),b.size());

        for(int i=0;i<l;i++)
        {
                if(a[i]!=b[i])
                        return false;
        }

        return true;
}

int main()
{
        int t,n,i;
        vector<string>v;
        scanf("%d",&t);

        while(t--)
        {
                v.clear();
                scanf("%d",&n);

                string s;

                for(i=0;i<n;i++)
                {
                        cin>>s;
                        v.push_back(s);
                }

                sort(v.begin(),v.end());

                bool flag=true;

                for(i=0;i<n-1;i++)
                {
                        if(check(v[i],v[i+1]))
                        {
                                flag=false;
                                break;
                        }
                }

                if(flag)
                        cout<<"YES"<<endl;
                else
                        cout<<"NO"<<endl;
        }

        return 0;
}
