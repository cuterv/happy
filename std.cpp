#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<stdlib.h>
using namespace std;
#define love ios::sync_with_stdio(false);cin.tie(nullptr),cout.tie(nullptr);
typedef long long int ll;
const int N = 1e6+10;
int n,q,vv,uu;
char s[3][N];
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int i,int j)
{
    int x=find(i),y=find(j);
    if(x!=y) fa[y]=x;
}
struct node
{
	int x,y;
}v,u;
int dfs(node v,node u,int cnt,node pre)
{
	if(v.x==u.x&&v.y==u.y)
	{
		return cnt;
	}
	cnt++;
	for(int i=0;i<3;i++)
	{
		int xx=v.x,yy=v.y;
		if(i==1)
		{
			xx++;
		}
		else if(i==2)
		{
			xx--;
		}
		else if(i==0)
		{
			if(v.y<u.y) yy++;
			else if(v.y>u.y) yy--;
			else continue;
		}
		if(xx<1||xx>2||yy<1||yy>n)
		{
			continue;
		}
		if(xx==pre.x&&yy==pre.y)
		{
			continue;
		}
		if(s[xx][yy]=='X')
		{
			continue;
		}
		node sup;
		sup.x=xx,sup.y=yy;
		if(dfs(sup,u,cnt,v)!=-1)
		{
			return dfs(sup,u,cnt,v);
		}
	}
	return -1;
}
int main()
{
	love;
	cin>>n>>q;
	for(int i=1;i<=2*n+5;i++)
	{
		fa[i]=i;
	}
	for(int j=1;j<=2;j++)
		for(int i=1;i<=n;i++)
			cin>>s[j][i];
	for(int i=1;i<=n;i++)
	{
		
	}
	while(q--)
	{
		cin>>vv>>uu;
		if(vv>n)
		{
			v.x=2;
			v.y=vv-n;
		}
		else
		{
			v.x=1;
			v.y=vv;
		}
		if(uu>n)
		{
			u.x=2;
			u.y=uu-n;
		}
		else
		{
			u.x=1;
			u.y=uu;
		}
		node p;
		p.x=0;p.y=0;
		cout<<dfs(v,u,0,p)<<endl;
	}
}