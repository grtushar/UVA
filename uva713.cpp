using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define max(a,b) ((a>b)?(a):(b))

/*void Reverse(string &theWord)
{
        int i,lenn=theWord.length();
        char temp;

        for (i=0; i<lenn/2; i++)
        {
        	temp = theWord[i];
        	theWord[i] = theWord[lenn-i-1];
        	theWord[lenn-i-1] = temp;
        }
}

int rev(int x)
{
    int ans=0;
    while(x)
    {
        ans=ans*10+(x%10);
        x/=10;
    }

    return ans;
}*/


int main()
{

    int T,i,len1,len2,temp,carry,ans[300],j,a[300],b[300];
    char a1[300],b1[300];
    cin>>T;
    getchar();

    while(T--)
    {

        memset(a,0,sizeof a);
        memset(b,0,sizeof b);

        //getline(cin,a);
        //getline(cin,b);
        scanf("%s",&a1);
        scanf("%s",&b1);

        len1=strlen(a1);

        for(i=0;i<len1;i++)
            a[i]=a1[i]-48;

        len2=strlen(b1);
        for(i=0;i<len2;i++)
            b[i]=b1[i]-48;

        int len=max(len1,len2);

        carry=0;

        for(i=0;i<len;i++)
        {
            temp=(a[i])+(b[i])+carry;
            ans[i]=temp%10;
            carry=temp/10;
        }




       /* Reverse(a);
        Reverse(b);

        len1=a.length()-1;
        len2=b.length()-1;

        carry=i=0;

        while(len1>=0&&len2>=0)
        {
            temp=(a[len1--]-48)+(b[len2--]-48)+carry;
            ans[i++]=temp%10;
            carry=temp/10;
        }

        if(len1>=0)
        {
            while(len1>=0)
            {
                temp=(a[len1--]-48)+carry;
                ans[i++]=temp%10;
                carry=temp/10;
            }
        }

        else if(len2>=0)
        {
            while(len2>=0)
            {
                temp=(b[len2--]-48)+carry;
                ans[i++]=temp%10;
                carry=temp/10;

            }
        }*/

        while(carry!=0)
        {
            ans[i++]=carry%10;
            carry/=10;
        }
        j=0;

        while(ans[j]==0)
            j++;

        while(j<i)
            cout<<ans[j++];

        cout<<endl;


    }

    return 0;
}
