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
#define love ios::sync_with_stdio(false);cin.tie(nullptr),cout.tie(nullptr);
const int N=505;
vector<int> g[N];
int v,e,k,c[N],isv[N];
int bfs(int u)
{
    int v;
    isv[u]=1;
    for(int i=0;i<(int)g[u].size();i++)
    {
        v=g[u][i];
        if(c[u]==c[v])
        {
            return 0;
        }
        if(isv[v]==0)
        {
            int ans=bfs(v);
            if(ans==0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    love;
    cin>>v>>e>>k;
    int x,y;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int h;
    cin>>h;
    while(h--)
    {
        for(int i=0;i<=N-1;i++)
        {
            isv[i]=0;
        }
        int lg=1,num=0;
        map<int,int> m;
        for(int i=1;i<=v;i++)
        {
            cin>>c[i];
            if(m[c[i]]==0)num++;
            m[c[i]]++;
        }
        if(num!=k)lg=0;
        if(lg)
        {
            int ans,aa=1;
            for(int i=1;i<=v;i++)
            {
                ans=dfs(i);
                if(ans==0)aa=0;
            }
            if(aa)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else cout<<"No"<<endl;
    }
}