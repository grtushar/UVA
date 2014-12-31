using namespace std;

#include<iostream>

int main()
{
    int arr[1010],n,chk,i;

    while(cin>>n&&n>0)
    {
        chk=0;
        for(i=0;i<n;i++)
            cin>>arr[i];

        for(i=0;i<n;i++)
        {
            if(arr[i])
            {
                if(chk)
                    cout<<" ";
                cout<<arr[i];
                chk=1;
            }
        }

        if(chk==0)
            cout<<0;

        cout<<endl;
    }

    return 0;
}
