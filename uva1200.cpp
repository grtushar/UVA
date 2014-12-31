// wrong answer


using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
        int t,a,b,i,temp,cnt,a1,a2,b1,b2;
        char str[300];
        scanf("%d",&t);
        //getchar();

        while(t--)
        {
                scanf("%s",str);

                a1=a2=b1=b2=i=0;
                bool flag=false;

                while(str[i]!='=')
                {
                        temp=0;
                        while(str[i]!='+'&&str[i]!='-'&&str[i]!='x'&&str[i]!='=')
                        {
                                temp=temp*10+(str[i]-48);
                                i++;
                        }

                        //cout<<":: "<<temp<<endl;
                        if(flag){
                                temp=-temp;
                                flag=false;
                        }

                        if(str[i]=='x')
                        {
                                if(i-1>=0)
                                {
                                        if(str[i-1]=='-') temp=-1;
                                        else if(str[i-1]=='+') temp=1;
                                }
                                if(i-1<0) temp=1;
                                a1+=temp; i++;
                        }
                        else
                        {
                                b1+=temp;
                        }
                         if(str[i]=='-') flag=true;
                        if(str[i]=='=') break;
                        i++;
                }

                //cout<<a1<<"  "<<b1<<endl;

                i++;
                flag=false;
                while(str[i])
                {
                        temp=0;
                        while(str[i]!='+'&&str[i]!='-'&&str[i]!='x'&&str[i])
                        {
                                temp=temp*10+(str[i]-48);
                                i++;
                        }

                        if(flag){
                                temp=-temp;
                                flag=false;
                                //cout<<"done"<<endl;
                        }

                        if(str[i]=='x')
                        {

                                if(str[i-1]=='-') temp=-1;
                                else if(str[i-1]=='+'||str[i-1]=='=') temp=1;

                                a2+=temp; i++;
                        }
                        else
                        {
                                b2+=temp;
                        }
                        if(str[i]=='-') flag=true;

                        if(!str[i]) break;
                        i++;
                }

                /*cout<<a1<<"  "<<a2<<endl;
                cout<<b1<<"  "<<b2<<endl;*/

                a=a1-a2;
                b=b2-b1;

               // cout<<a<<"   "<<b<<endl;

                if(a<0&&b<0) {a*=-1; b*=-1;}

                if(a==0)
                {
                        if(b==0)
                                  printf("IDENTITY\n");
                        else
                                printf("IMPOSSIBLE\n");
                }

                else
                {
                        printf("%d\n",b/a);
                }

        }

        return 0;
}
