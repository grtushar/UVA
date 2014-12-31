using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
        int n,i,j;
        char ch[100][10]={"i","ii","iii","iv","v","vi","vii","viii","ix","x","xi","xii","xiii","xiv","xv","xvi","xvii","xviii","xix","xx","xxi","xxii","xxiii","xxiv","xxv","xxvi","xxvii","xxviii","xxix","xxx","xxxi","xxxii","xxxiii","xxxiv","xxxv","xxxvi","xxxvii","xxxviii","xxxix","xl","xli","xlii","xliii","xliv","xlv","xlvi","xlvii","xlviii","xlix","l","li","lii","liii","liv","lv","lvi","lvii","lviii","lix","lx","lxi","lxii","lxiii","lxiv","lxv","lxvi","lxvii","lxviii","lxix","lxx","lxxi","lxxii","lxxiii","lxxiv","lxxv","lxxvi","lxxvii","lxxviii","lxxix","lxxx","lxxxi","lxxxii","lxxxiii","lxxxiv","lxxxv","lxxxvi","lxxxvii","lxxxviii","lxxxix","xc","xci","xcii","xciii","xciv","xcv","xcvi","xcvii","xcviii","xcix","c"};

        while(scanf("%d",&n)&&n)
        {
               int arr[6]={0};

               for(i=0;i<n;i++)
               {
                       int l=strlen(ch[i]);
                       for(j=0;j<l;j++)
                        {
                                if(ch[i][j]=='i')
                                        arr[1]++;
                                else if(ch[i][j]=='v')
                                        arr[2]++;
                                else if(ch[i][j]=='x')
                                        arr[3]++;
                                else if(ch[i][j]=='l')
                                        arr[4]++;
                                else
                                        arr[5]++;
                        }
               }

              printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,arr[1],arr[2],arr[3],arr[4],arr[5]);
        }

        return 0;
}

/*
int ans[105][8]={0},temp[5]={1,5,10,50,100},i,j,value,n;

        for(i=1;i<=100;i++)
        {
                value=i;
                if(value==40)
                {
                        ans[i][3]=1;
                        ans[i][4]=1;
                }
                else if(value==90)
                {
                        ans[i][3]=1;
                        ans[i][5]=1;
                }
                else
                {
                        for(j=4;j>=0;j--)
                        {
                                if(value>1&&value==(temp[j]-1))
                                {
                                        ans[i][j+1]+=1;
                                        value=1;
                                }
                                else if(value>=temp[j])
                                {
                                        ans[i][j+1]=value/temp[j];
                                        value%=temp[j];
                                        if(value>1&&value==temp[j]-1)
                                        {
                                                ans[i][j+1]+=1;
                                                value=1;
                                                j=1;
                                        }
                                }
                        }
                }
                //ans[i][j]=value;
                cout<<i<<"   :   ";
             for(j=1;j<=5;j++)
                cout<<ans[i][j]<<"   ";
               cout<<endl;
        }
*/
