#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<stack>
#include<string.h>
using namespace std;
#define love ios::sync_with_stdio(false);cin.tie(nullptr),cout.tie(nullptr);
typedef long long ll;
const int inf = 0x3f3f3f3f;
const double INF = 1e18;
const int N = 1e5+10; 
const double pi = acos(-1.0);
int n,m,s,isv[N]={0},ans[N];
int fa[N][22];//fa[u][i]代表从u节点往上跳2^i步到达节点；
int dep[N];//dep[u]代表u节点在树上的深度；
vector<pair<int,int> > g[N];
/*int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int i,int j)
{
    int x=find(i),y=find(j);
    if(x!=y) fa[y]=x;
}*/
void dfs(int u,int par)
{
    dep[u]=dep[par]+1;
    fa[u][0]=par;
    for(int i=1;i<=20;i++)
    {
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
}
int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 20; i >= 0; i--)
    {
        if (dep[fa[u][i]]>= dep[v])
            u = fa[u][i];
    }
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
    {
        if (fa[u][i] != fa[v][i])
        u = fa[u][i], v = fa[v][i];
    }
    return fa[u][0];
}
int main()
{
    love;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
        }
        int x,y,v;
        for(int i=1;i<n;i++)
        {
            pair<int,int> sup;
            cin>>x>>y>>v;
            sup.first=v;
            sup.second=y;
            g[x].push_back(sup);
            sup.second=x;
            g[y].push_back(sup);
        }
        while(m--)
        {
            cin>>x>>y;
            cout<<dij(x,y)<<endl;
        }
    }
}