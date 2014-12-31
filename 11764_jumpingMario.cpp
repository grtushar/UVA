#include<iostream>

using namespace std;

int main()
{
    int T,arr[55],i,N,high_jump,low_jump,Case=1;
    cin>>T;

    while(T--)
    {
        low_jump=high_jump=0;
        cin>>N;
        for(i=0;i<N;i++)
        {
            cin>>arr[i];
            if(i&&arr[i]>arr[i-1])
            high_jump++;
            else if(i&&arr[i]<arr[i-1])
            low_jump++;
        }
        cout<<"Case "<<Case++<<": "<<high_jump<<" "<<low_jump<<endl;
    }
    return 0;
}
