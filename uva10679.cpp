using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
#include<map>
#include<algorithm>

#define N 100000+10

char str[N],qstr[1000+10];
int sa[N],lcp[N];
bool cmp(int a, int b)
{
        return strcmp(str+a, str+b)<0;
}

int main()
{
        int t,q,n,lq,i,x,y,cnt,temp;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%s",str);
                n=strlen(str);
                for(i=0;i<n;i++) sa[i] = i;
                sort(sa,sa+n,cmp);

                lcp[0] = 0;
                for(i=1;i<n;i++)
                {
                        cnt=0;
                        for(x=sa[i],y=sa[i-1];str[x]==str[y];x++,y++) cnt++;
                        lcp[i] = cnt;
                }

                scanf("%d",&q);

                while(q--)
                {
                        scanf("%s",qstr);
                        lq = strlen(qstr);

                        bool flag=false;

                        for(i=0;i<n&&!flag;i++)
                        {
                                temp=n-sa[i];
                                if(lcp[i]==0)
                                {
                                        cnt=0;
                                        for(x=sa[i],y=0;y<lq&&x<temp&&str[x]==qstr[y];x++,y++) cnt++;
                                        if(cnt==lq) {
                                                flag=true;
                                                break;
                                        }
                                }
                        }

                        if(flag) printf("y\n");
                        else printf("n\n");
                }
        }

        return 0;
}
