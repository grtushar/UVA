using namespace std;

#include<iostream>
#include<cstring>

string str;

void binary(long long int k)
{
    long long int i;
    for(i=k;i>=0;i--)
        cout<<str[i];
}

int main()
{
    long long int I,k,cnt,temp;


    while(cin>>I&&I)
    {
        cnt=0;
        k=0;
        while(I)
        {
            temp = I%2;
            if(temp==1)
            {
                cnt++;
                str[k++] = '1';
            }
            else
            {
                str[k++] = '0';
            }

            I = I/2;
        }


        cout<<"The parity of ";
        binary(k-1);
        cout<<" is "<<cnt<<" (mod 2)."<<endl;

    }
    return 0;
}
