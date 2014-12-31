using namespace std;

#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    vector<int>v;
    int n,l;

    while(cin>>n)
    {
        v.push_back(n);
        sort(v.begin(),v.end());
        l=v.size();

        if(l%2)
        {
            cout<<v[l/2]<<endl;
        }
        else
        {
            cout<<(v[(l/2)-1]+v[l/2])/2<<endl;
        }
    }

    return 0;
}
