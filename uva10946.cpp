using namespace std;

#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>

struct M{
    char c;
    int ocr;
}node[3000];


char c[55][110],d;
int s,i,x,y,j,cnt;



void dfs (int r, int ch, char k)
{

    if ( r < 0 || r == x || ch < 0 || ch == y || c [r] [ch] != k )
        return;
    cnt++;
    c [r] [ch] = '.';
    dfs (r - 1, ch, k);
    dfs (r + 1, ch, k);
    dfs (r, ch + 1, k);
    dfs (r, ch - 1, k);
}

bool cmp(M a,M b)
{
    if(a.ocr>b.ocr)
        return true;
    if(a.ocr==b.ocr&&a.c<b.c)
        return true;
    return false;
}




int main()
{
    int Case=1;
    while(scanf("%d%d",&x,&y)==2)
    {
        if(x==0&&y==0)
            break;
        for(i=0;i<x;i++)
        {
            scanf("%s",c[i]);
        }
        s=0;

        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                if(c[i][j]!='.')
                {
                    cnt=0;
                    node[s].c=c[i][j];
                    dfs(i,j,c[i][j]);


                    node[s++].ocr=cnt;
                }
            }
        }

        sort(node, node+s,cmp);

        printf ("Problem %d:\n",Case++);


        for(i=0;i<s;i++)
            cout<<node[i].c<<" "<<node[i].ocr<<endl;


    }

    return 0;
}
/*void insert(int c,int value)
{

    struct M *newnode;
    newnode = new M;
    newnode->c=c;
    newnode->ocr=value;

    if(!head)
    {
        head=newnode;
        head->next=NULL;
    }

    else
    {
        struct M *p=head,*q=NULL;
        while(p&&value<p->ocr)
        {
            q=p;
            p=p->next;
        }
        if(q==NULL)
        {
            newnode->next=head;
            head=newnode;
        }
        else
        {
            q->next=newnode;
            newnode->next=p;
        }

    }
}*/

/*struct M *p=head;
        while(p)
        {
            cout<<p->c<<" "<<p->ocr<<endl;
            p=p->next;
        }*/
