using namespace std;

#include<iostream>
#include<algorithm>

#define n 2000010

int arr[n];

int main()
{
    long long int T,i;

    while(cin>>T&&T)
    {
        for(i=0;i<T;i++)
            cin>>arr[i];

        sort(arr,arr+T);

        for(i=0;i<T;i++)
        {
            cout<<arr[i];
            if(i+1<T)
                cout<<" ";
        }

        cout<<endl;
    }
    return 0;
}
