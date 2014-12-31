using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
        char str[1000], sum[1000];
        int k, l1, l2, carry, temp;

        scanf("%s",sum);

         int i,l=strlen(sum)-1;
         k=l+1;
        for(i=0;i<=k/2;i++)
        {
                int c = sum[i];
                sum[i] = sum[l];
                sum[l] = c;
                l--;
        }

        while(scanf("%s",str)==1)
        {
                if(str[0]=='0'&&strlen(str)==1)
                        break;

                l1 = strlen(sum);
                l2 = strlen(str);

                k=carry=0;
                l2--;

                while(k<l1&&l2>=0)
                {
                        temp = (sum[k]-48) + (str[l2]-48) +carry;
                        sum[k] = (temp%10)+48;
                        carry = temp/10;
                        k++;l2--;
                }

                while(k<l1)
                {
                        sum[k] = ((sum[k]-48)+carry)+48;
                        carry/=10;
                        k++;
                }

                while(l2>=0)
                {
                        sum[k] = ((str[l2]-48)+carry)+48;
                        carry/=10;
                        k++;
                        l2--;
                }

                if(carry)
                {
                        sum[k++]=carry+48;
                }
        }

        l=strlen(sum)-1;
        for(i=0;i<=k/2;i++)
        {
                int c = sum[i];
                sum[i] = sum[l];
                sum[l] = c;
                l--;
        }

        cout<<sum<<endl;

        return 0;
}
