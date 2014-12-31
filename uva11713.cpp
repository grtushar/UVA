using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

bool vowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
    return false;
}

int main()
{
    int t,i,l1,l2;
    bool flag;
    string str1,str2;
    scanf("%d",&t);

    while(t--)
    {
        cin>>str1>>str2;
        l1=str1.length();
        l2=str2.length();

        if(l1==l2)
        {
            flag=false;
            for(i=0;i<l1;i++)
            {
                if(str1[i]!=str2[i])
                {
                    if(vowel(str1[i])&&vowel(str2[i]))
                    {
                        continue;
                    }
                    else
                    {
                        flag=true;
                        break;
                    }
                }
            }

            if(i>=l1)
                printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

        if(flag)
        {
            printf("No\n");
        }
    }

    return 0;
}
