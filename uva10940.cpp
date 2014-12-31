using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<list>
#include<math.h>

int main()
{
        long n,i=1,temp,ans;
         while(scanf("%ld",&n)&&n)
         {
                 i=1;
                temp=pow(2,i);
                while(temp<n)
                {
                        i++;
                        temp=pow(2,i);
                        //cout<<"power  ::"<<temp<<endl;
                }
                if(n==1)
                {
                        cout<<'1'<<endl;
                }
                else if(temp==n)
                        cout<<temp<<endl;
                else
                {
                        ans=temp-(temp-n)*2;
                        cout<<ans<<endl;
                }

         }

         return 0;
}

/*
cout<<"ans :: ";
                 if(arr[n])
                 {
                         cout<<arr[n]<<endl;
                 }
                 else
                 {
                           list<int>listing;
                         for(i=n;i>0;i--)
                                listing.push_back(i);
                        list<int>::iterator pa=listing.begin(),it=listing.end();
                        it--;
                        //cout<<*it<<"    "<<*pa<<endl;

                        while(--it!=listing.begin())
                         {

                                temp=*it;

                               pa=listing.begin();
                                listing.insert(pa,temp);
                                //cout<<temp<<"    "<<*it<<"     "<<*pa<<endl;
                                it--;
                         }
                         //cout<<k<<endl;
                        arr[n]=*it;
                        cout<<arr[n]<<endl;
                 }

                 ,arr[500000+10]={0};

        arr[1]=1;
       /* for(long k=2;k<=500000;k++)
        {
                list<int>listing;
                 for(i=k;i>0;i--)
                        listing.push_back(i);
                list<int>::iterator pa=listing.begin(),it=listing.end();
                it--;
                //cout<<*it<<"    "<<*pa<<endl;

                while(--it!=listing.begin())
                 {

                        temp=*it;

                       pa=listing.begin();
                        listing.insert(pa,temp);
                        //cout<<temp<<"    "<<*it<<"     "<<*pa<<endl;
                        it--;
                 }
                 //cout<<k<<endl;
                arr[k]=*it;
        }*/


