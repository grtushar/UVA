using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
    int n,arr[10010],i;

    while(cin>>n&&n>0)
    {
        int count=1;
        bool up=false,down=false;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        arr[n]=arr[0];

        if(arr[0]>arr[1])
            up=true;
        else
            down=true;

        for(i=2;i<=n;i++)
        {
            if(down&&arr[i-1]>arr[i])
            {
                count++;
                down=false;
                up=true;
            }
            else if(up&&arr[i-1]<arr[i])
            {
                count++;
                down=true;
                up=false;
            }
        }

        if(down&&arr[0]<arr[1])
            count--;
        else if(up&&arr[0]>arr[1])
            count--;

        cout<<count<<endl;
    }

    return 0;
}
