#include<iostream>
#include<cstring>
#include<math.h>
#include<cstdio>

using namespace std;

#define MAX_N 2

struct Matrix
{
       long long int mat[MAX_N][MAX_N];
};
long long int N,M;

Matrix matMul(Matrix a,Matrix b)
{
       Matrix ans;
       long long int i,j,k;
      for(i=0;i<MAX_N;++i)
        for(j=0;j<MAX_N;j++)
        {
                      for(ans.mat[i][j]=k=0;k<MAX_N;k++)
                      {
                             ans.mat[i][j]=((ans.mat[i][j]%M)+(((a.mat[i][k]%M)*(b.mat[k][j]%M)%M)))%M;
                      }
        }
       return ans;
}
Matrix matPow(Matrix Base,long long int p)
{
       if(p==1) return Base;
       Matrix X=matPow(Base,p/2);
       X=matMul(X,X);
       if(p & 1) X=matMul(X,Base);
       return X;
}



int main()
{

    while(cin>>N>>M)
    {
            if(N>=1)
            {
                   Matrix Base;
                   Base.mat[0][0]=Base.mat[0][1]=Base.mat[1][0]=1;
                   Base.mat[1][1]=0;
                   M=pow(2,M);
                   Matrix ans=matPow(Base,N-1);
                   printf("%lld\n",ans.mat[0][0]%M);
            }
            else
                printf("0\n");

    }

    return 0;
}
