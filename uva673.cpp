using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>

char str[150];
stack<char>st;

bool parenthesis()
{
    int l=strlen(str),i;

    for(i=0;i<l;i++)
    {
        if(str[i]=='('||str[i]=='[')
            st.push(str[i]);
        else if(str[i]==')')
        {
            if(st.empty()||st.top()!='(')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        else
        {
            if(st.empty()||st.top()!='[')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }

    if(st.empty())
        return true;
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();

    while(t--)
    {
       gets(str);

        if(str[0]==NULL||parenthesis())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

        while(!st.empty())
        {
            st.pop();
        }
    }

    return 0;
}
