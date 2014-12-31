#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string str;
    int count,l;
    cin>>count;

    while(count--)
    {
        cin>>str;
        l=str.length();
        if(l==5)
        cout<<"3"<<endl;
        else
        {
            if((str[0]=='t'&&(str[1]=='w'||str[2]=='o'))||(str[1]=='w'&&(str[0]=='t'||str[2]=='o'))||(str[2]=='o'&&(str[1]=='w'||str[0]=='t')))
            cout<<"2"<<endl;
            else
            cout<<"1"<<endl;
        }
    }
    return 0;
}
