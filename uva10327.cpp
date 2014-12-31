using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
    int arr[1010],i,j,count,n;

    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>arr[i];

        count=0;

       for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(arr[i]>arr[j])
                count++;

        cout<<"Minimum exchange operations : "<<count<<endl;
    }

    return 0;
}
