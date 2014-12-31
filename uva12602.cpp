using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>

int absolute(int x)
{
        if(x<0)
                return -x;
        return x;
}

int power(int x, int y)
{
        int ans=1,i;
        for(i=0;i<y;i++)
                ans*=x;
        return ans;
}

int main()
{
        char str[10];
        int t, digit, alpha, i;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%s",str);
                digit=alpha=0;

                for(i=0;i<3;i++)
                {
                        alpha+=(int)(str[i]-65)*power(26,2-i);
                        //cout<<str[i]-65<<"   "<<alpha<<endl;
                }

                for(i=4;i<8;i++)
                {
                        digit=(digit*10)+(str[i]-48);
                }

                //cout<<digit<<"    "<<alpha<<endl;

                if(absolute(alpha-digit)<=100)
                        printf("nice\n");
                else
                        printf("not nice\n");
        }

        return 0;
}
