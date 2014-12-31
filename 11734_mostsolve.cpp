#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char s1[50],s2[50],ss1[50],ss2[50];
    int l1,l2,cnt=1,n,i,k,j;
    scanf("%d",&n);
    getchar();

    while(n--)
    {
       gets(s1);
       gets(s2);
        l1=strlen(s1);
        l2=strlen(s2);

        k=0;
        for(i=0;i<l1;i++)
        {
            if(isalpha(s1[i]))
            ss1[k++]=s1[i];
        }
        ss1[k]=NULL;

         k=0;
        for(i=0;i<l2;i++)
        {
            if(isalpha(s2[i]))
            ss2[k++]=s2[i];
        }
        ss2[k]=NULL;

        if(!(strcmp(ss1,ss2)==0)&&(l1>l2))
        printf("Case %d: Wrong Answer\n",cnt++);
        else if(l1>l2)
         printf("Case %d: Output Format Error\n",cnt++);
         else if(strcmp(s1,s2)==0)
         printf("Case %d: Yes\n",cnt++);
         else
          printf("Case %d: Wrong Answer\n",cnt++);

    }
    return 0;

}
