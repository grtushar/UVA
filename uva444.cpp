using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>

int int_check(char c)
{
    int d=c,temp=0;

    while(d)
    {
        temp=(temp*10)+(d%10);
        d/=10;
    }

    return temp;
}

bool check(int temp)
{
    if(temp==32||temp==33||temp==44||temp==46||temp==58||temp==59||temp==63||(temp>=65&&temp<=90)||(temp>=97&&temp<=122))
        return false;
    return true;
}

int main()
{
    //printf("%c",9);
    int i,l,temp;
    string str;

    while(getline(cin,str))
    {
        l=str.length();

        if( str[0] > 47 && str[0] < 58)//isdigit(str[0]))
        {
            for(i=l-1;i>=0;i--)
            {
                temp=0;
                while(check(temp)&&i>=0)
                {
                    temp=(temp*10)+(str[i]-48);
                    if(temp<30)
                        i--;
                }
                printf("%c",temp);
            }
        }
        else
        {
            for(i=l-1;i>=0;i--)
            {
                int ans=str[i];
                if(ans%10==0)
                {
                    if(ans==100)
                         printf("00");
                    else
                         printf("0");
                }
                printf("%d",int_check(str[i]));
            }
        }

        printf("\n");
    }
    return 0;
}
