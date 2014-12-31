using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
        int t,n,m;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&n,&m);
                if(n==m)
                {
                        cout<<"1"<<endl;
                }
                else
                {
                         n=n-m+1;
                        int cnt=1;
                        while(n>=m)
                        {
                                if(n==m)
                                {
                                        cnt++;
                                        n=0;
                                }
                                else
                                {
                                        n=n-m+1;
                                        cnt++;
                                 }
                        }

                        if(n==0)
                                printf("%d\n",cnt);
                        else
                                printf("cannot do this\n");
                }
        }

        return 0;
}
