using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>

int main()
{
    string str,cstr,astr;
    int n,max,i,l;

    while(cin>>n)
    {
        cin>>str;
        map<string,int>m;
        max=0;
        l=str.length();

        for(i=0;i<l-n;i++)
        {
            cstr=str.substr(i,n);
            if(++m[cstr]>max)
            {
                max=m[cstr];
                astr=cstr;
            }
        }

        cout<<astr<<endl;
    }

    return 0;
}



/* //cstr.assign(str.begin()+i,str.begin()+i+n);
            cstr=str.substr(i,n);

            //cout<<cstr<<endl;
            m[cstr]++;
            //cout<<m[cstr]<<endl;


            if(m[cstr]>max)
            {
               // cout<<cstr<<" "<<m[cstr]<<" "<<"enter"<<endl;
                max=m[cstr];
                astr=cstr;
                //astr.assign(cstr.begin(),cstr.begin()+n);
            }*/
