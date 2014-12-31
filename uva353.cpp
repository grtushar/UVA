using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>

string str;

bool cheaque(string s)
{
            int l = s.size();
            for(int i=0,j=l-1;i<l/2;i++,j--)
            {
                    if(s[i]!=s[j]) return false;
            }

             return true;
}

int main()
{
            int l,i,j;

            while(cin>>str)
            {
                        l=str.length();
                        string rep;
                        set<string>st;

                        for(i=0;i<l;i++) {
                                rep=str[i];
                                st.insert(rep);
                        }

                       for(i=2;i<=l;i++)
                      {
                        for(j=0;j<=l-i;j++)
                        {
                                string rep=str.substr(j,i);
                                                        //cout<<rep<<endl;
                                if(cheaque(rep))
                                        st.insert(rep);
                        }
                      }

                        cout<<"The string '"<<str<<"' contains "<<st.size()<<" palindromes."<<endl;
                        str.clear();
            }

    return 0;
}
