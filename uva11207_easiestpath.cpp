using namespace std;

#include<iostream>

int main()
{
    long long int n,w,h,temp,max,i,arr[10000];

    while(cin>>n&&n)
    {
        for(i=0;i<n;i++)
        {
            cin>>w>>h;
            arr[i]=(w*h)/4;
        }

        max=arr[0];
        temp=0;

        for(i=1;i<n;i++)
        {
            if(max<arr[i])
            {
                max=arr[i];
                temp=i;
            }
        }

        cout<<temp+1<<endl;
    }
    return 0;
}
