using namespace std;

#include<iostream>
#include<cstring>

int solve(char c)
{
    if(c=='B'||c=='F'||c=='P'||c=='V')
        return 1;
    else if(c=='C'||c=='G'||c=='J'||c=='K'||c=='Q'||c=='S'||c=='X'||c=='Z')
        return 2;
    else if(c=='D'||c=='T')
        return 3;
    else if(c=='L')
        return 4;
    else if(c=='M'||c=='N')
        return 5;
    else if(c=='R')
        return 6;
    else
        return 0;
}

int main()
{
    string str;
    int i,temp,l;

    while(cin>>str)
    {
        temp=0;
        l=str.length();
        for(i=0;i<l;i++)
        {

            if(i==0)
            {
                temp=solve(str[i]);
                if(temp)
                    cout<<temp;
            }
            else if(temp!=solve(str[i]))
            {
                temp=solve(str[i]);
                if(temp)
                    cout<<temp;
            }


        }
        cout<<endl;
    }
}
