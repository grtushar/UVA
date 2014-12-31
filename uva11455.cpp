using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

int main()
{
        long long int arr[4],t;
        scanf("%lld",&t);

        while(t--)
        {
                cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
                sort(arr,arr+4);

                if(arr[0]==arr[1]&&arr[1]==arr[2]&&arr[2]==arr[3])
                        printf("square\n");
                else if(arr[0]==arr[1]&&arr[2]==arr[3])
                        printf("rectangle\n");
                else if(arr[0]+arr[1]+arr[2]>arr[3])
                        printf("quadrangle\n");
                else
                        printf("banana\n");
        }

        return 0;
}
