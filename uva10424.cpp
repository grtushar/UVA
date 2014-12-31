using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
    string str1,str2;
    int sl1,sl2,i,sum1,sum2,temp;
    char c;

    while(getline(cin,str1)&&getline(cin,str2))
    {

        sum1=sum2=0;
        sl1=str1.length();
        sl2=str2.length();

        for(i=0;i<sl1;i++)
        {
            if(isalpha(str1[i]))
            {
                c=tolower(str1[i]);
                sum1=sum1+(c-96);
            }
        }

        while(sum1%10!=sum1)
        {

            temp=sum1;
            sum1=0;
            while(temp)
            {
                sum1=sum1+temp%10;
                temp/=10;
            }
        }

        for(i=0;i<sl2;i++)
        {
            if(isalpha(str2[i]))
            {
                c=tolower(str2[i]);
                sum2=sum2+c-96;
            }
        }

        while(sum2%10!=sum2)
        {

            temp=sum2;
            sum2=0;
            while(temp)
            {
                sum2=sum2+temp%10;
                temp/=10;
            }
        }


        if(sum2<=sum1)
            printf("%.2lf %%\n",(((double)sum2/(double)sum1)*100));
        else
            printf("%.2lf %%\n",(((double)sum1/(double)sum2)*100));
    }

    return 0;
}
