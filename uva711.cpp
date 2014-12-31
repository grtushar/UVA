using namespace std;

#include<iostream>
#include<cstring>
#include<cmath>

#define max(a,b) (((a)>(b))?(a):(b))
#define N 60005
#define maxItem 10


int dp[maxItem][N],val[maxItem],maxV;

int solve(int item,int W)
{
    if(item>6)
        return 0;
    if(dp[item][W]!=-1)
       return dp[item][W];

    if(val[item]&&maxV>=(W+item))
    {
        if(val[item]-1==0)
        {
            return dp[item][W] = max(item+solve(item+1,W+item),solve(item+1,W));
        }

        else
        {
            val[item]--;
            return dp[item][W] = max(item+solve(item,W+item),solve(item,W));
        }
    }

    else
    {
            return dp[item][W] = solve(item+1,W);
    }
}

int main()
{
   int sum,i,j,ans,Case=1;

    while(cin>>val[1]>>val[2]>>val[3]>>val[4]>>val[5]>>val[6])
    {
        if(val[1]==0&&val[2]==0&&val[3]==0&&val[4]==0&&val[5]==0&&val[6]==0)
            break;
        memset(dp,-1,sizeof(dp));
        sum=0;
        for(i=1;i<=6;i++)
        {
            sum+=(val[i]*i);
        }

        if(sum%2)
        {
            cout<<"Collection #"<<Case++<<":"<<endl<<"Can't be divided."<<endl;
        }
        else
        {
            maxV = sum/2;

            ans = solve(1,0);

            cout<<ans<<" "<<maxV<<" "<<sum<<endl;

            if(ans==maxV)
            {
                cout<<"Collection #"<<Case++<<":"<<endl<<"Can be divided."<<endl;
            }
            else
            {
                cout<<"Collection #"<<Case++<<":"<<endl<<"Can't be divided."<<endl;
            }
        }

        cout<<endl;

    }
    //cout<<endl;
    return 0;
}







/*using namespace std;

#include<iostream>
#include<cstring>
#include<cmath>

#define max(a,b) (((a)>(b))?(a):(b))
#define N 60000+5
#define maxItem 20005

//int max(int a, int b) { return (a > b)? a : b; }

int iabs(int n)
{
    return (n > 0)? n : -n;
}

int dp[maxItem][N],val[maxItem],n,maxV;

int solve(int item,int W)
{
    if(item>n)
        return 0;
    if(dp[item][W]!=-1)
        return dp[item][W];

    if(maxV>=(W+val[item]))
        return dp[item][W] = max(val[item]+solve(item+1,W+val[item]),solve(item+1,W));
    else
        return dp[item][W] = solve(item+1,W);
}

int main()
{
   int mar[10],sum,i,j,k,ans,Case=1;
    while(cin>>mar[1]>>mar[2]>>mar[3]>>mar[4]>>mar[5]>>mar[6]&&(mar[1]||mar[2]||mar[3]||mar[4]||mar[5]||mar[6]))
    {
        memset(dp,-1,sizeof(dp));
        k=1,sum=0;
        for(i=1;i<=6;i++)
        {
            for(j=mar[i];j>0;j--)
            {
                val[k]=i;
                sum+=val[k];
                k++;
            }
        }
        n = k-1;
        if(sum%2)
        {
            cout<<"Collection #"<<Case++<<":"<<endl<<"Can't be divided."<<endl;
        }
        else
        {
            maxV = sum/2;

            ans = solve(1,0);
            cout<<sum<<" "<<maxV<<" "<<ans<<endl;
            if(ans==maxV)
            {
                cout<<"Collection #"<<Case++<<":"<<endl<<"Can be divided."<<endl;
            }
            else
            {
                cout<<"Collection #"<<Case++<<":"<<endl<<"Can't be divided."<<endl;
            }
        }

    }
    return 0;
}*/
