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
using namespace std;
const int N=1e6;
vector<pair<int,int> > g[N];
int dep[N],val[N][33],par[N][33];
void dfs(int u, int f)
{
    dep[u]=dep[f]+1;
    for (int i=0;i<g[u].size();i++) 
    {
        int vv=g[u][i].first;
        int xx=g[u][i].second;
        if (vv == f)continue;
        //处理往上一个点的情况
        par[vv][0]=u;
        val[vv][0]=xx;
        dfs(vv,u);
    }
}
// 在求解lca的过程中额外维护我们要的信息
int query(int u,int v) 
{
    int ans=1<<30;
    if (dep[u]>dep[v]) swap(u, v);
    int d=dep[v]-dep[u];
    for (int j=30;j>=0;j--)if(d>=1<<j) 
    {
        ans=min(ans,val[v][j]);
        v=par[v][j];
        d-=1<<j;
    }
    if (u==v)return ans;
    for (int j=30;j>=0;j--) if(par[u][j]!=par[v][j]) 
    {
        ans=min(ans,min(val[u][j],val[v][j]));
        u=par[u][j];
        v=par[v][j];
    }
    ans=min(ans,min(val[u][0],val[v][0]));
    return ans;
}
int main()
{
    int n,q;
    cin>>n>>q;
    for (int i=1,u,v,w;i<n;i++) 
    {
        // u 到 v 的权值为 w 的边
        cin>>u>>v>>w;
        pair<int,int> sup;
        sup.first=v;sup.second=w;
        g[u].push_back(sup);
        sup.first=u;
        g[v].push_back(sup);
    }
    dfs(1,0);
    for (int j=1; j<=30; j++)
    {
        for (int u=1;u<=n;u++)
        {
            par[u][j]=par[par[u][j-1]][j-1];
            val[u][j]=min(val[u][j-1],val[par[u][j-1]][j-1]);
        }
    }
    for (int i=1;i<=q;i++) 
    {
        int u,v;
        cin>>u>>v;
        cout<<query(u,v)<<endl;
    }
}