using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int T[1000010],l1,l2;
char str[1000010],str2[1000010];

void failure()
{
    T[0]=0;
    int k=0;

    for(int q=2;q<=l1;q++)
    {
        while(k>0&&str[k]!=str[q-1])
        {
            k=T[k];
        }

        if(str[k]==str[q-1])
            k++;
        T[q]=k;
    }
}

int kmp()
{
    int q=0;
    for(int i=0;i<l2;i++)
    {
        while(q>0&&str[q]!=str2[i])
            q=T[q];

        if(str[q]==str2[i])
            q++;
    }

    return q;
}

int main()
{
    int count,i,Case=1,ans;
    while(gets(str2))
    {
        l2=strlen(str2);
        count=l2-1;
        for(i=0;i<l2;i++)
        {
            str[i]=str2[count--];
        }
        l1=l2;

        failure();

        ans=kmp();

        for(i=0;i<l2;i++)
        {
            printf("%c",str2[i]);
        }

        while(ans<l1)
        {
            printf("%c",str[ans++]);
        }

        printf("\n");
    }

    /*for(i=0;i<l1;i++)
    {
        cout<<str[i]<<" -> "<<T[i]<<endl;
    }*/

    return 0;
}
