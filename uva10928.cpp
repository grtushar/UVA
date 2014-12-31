using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<sstream>
#include<vector>

int main()
{
        int t,p,x,i,count,max;
        scanf("%d",&t);
        vector<int>v;

        while(t--)
        {
                max=99999;
                v.clear();
                scanf("%d",&p);
                getchar();

                for(i=1;i<=p;i++)
                {
                        count=0;
                        string line;
                        getline(cin,line);
                        istringstream iss(line);

                        while(iss>>x)
                        {
                                count++;
                        }

                        if(count<max)
                        {
                                max=count;
                                v.clear();
                                v.push_back(i);
                        }
                        else if(count==max){
                                v.push_back(i);
                        }
                }

                sort(v.begin(),v.end());

                for(i=0;i<v.size();i++)
                {
                        cout<<v[i];
                        if(i+1<v.size())
                                cout<<" ";
                }
                cout<<endl;
        }

        return 0;
}
