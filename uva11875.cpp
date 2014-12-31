using namespace std;

#include<iostream>
#include<algorithm>

int main()
{
    int T,n,arr[25],i,Case=1;
    cin>>T;

    while(T--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);

        cout<<"Case "<<Case++<<": "<<arr[n/2]<<endl;
    }

    return 0;
}
