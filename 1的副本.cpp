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
const int N = 1e6+10;
const double pi = acos(-1.0);
int n,m,s,fa[N],isv[N]={0},ans[N];
vector<int> g[N];
vector<int>::iterator it;
vector<pair<int,int> > q[N];
vector<pair<int,int> >::iterator iit;
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int i,int j)
{
    int x=find(i),y=find(j);
    if(x!=y) fa[y]=x;
}
void dfs(int x,int f)
{
    isv[x]=1;
    int l=g[x].size(),ll=q[x].size();
    for(int i=0;i<l;i++)
    {
        if(g[x][i]==f) 
        {
            continue;
        }
        dfs(g[x][i],x);
        merge(x,g[x][i]);
    }
    for(int i=0;i<ll;i++)
    {
        if(isv[q[x][i].second])
        {
            ans[q[x][i].first]=find(q[x][i].second);
        }
    }
}
int main()
{
    love;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        pair<int,int> sup;
        sup.first=i;
        sup.second=y;
        q[x].push_back(sup);
        sup.second=x;
        q[y].push_back(sup);
    }
    dfs(s,0);
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<endl;
    }
}
/*struct na
{
    int a,b;
}line[N];*/
/*int qpow(int a, int k, int p)
{
    int res = 1;
    while(k)
    {
        if(k & 1) res = (ll) res*a % p;
        k >>= 1;
        a = (ll)a*a % p;
    }
    return res;
}*/
/*bool cmp(struct na a,struct na b)
{
    return a.v<b.v;
}*/
/*using namespace std;
#define love ios::sync_with_stdio(false);cin.tie(nullptr),cout.tie(nullptr);
#define all(a) a.begin(),a.end()
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e6+10;
const double pi = acos(-1.0);
int a[N],n,q,l,r,v;
stack<int> d;
string ty;
struct info{
    ll le,re,l,r;
};
info operator + (const info a,const info b){
    info c;
    if(a.le==a.r-a.l+1) c.le=a.le+b.le;
    else c.le=a.le;
    if(b.re==b.r-b.l+1) c.re=b.re+a.re;
    else c.re=b.re;
    c.l=a.l;c.r=b.r;
    return c;
}
struct node{
    int l, r;
    info val;
}seg[N*4];
void settag(int id,ll tag)
{
    seg[id].sum+=(seg[id].r-seg[id].l+1)*tag;
    seg[id].lazy+=tag;
}
void up(int id)
{
    if(seg[id*2+1].val.re==seg[id*2+1].r-seg[id*2+1].l+1) 
        seg[id].val.re=seg[id*2].val.re+seg[id*2+1].val.re;
    else 
        seg[id].val.re=seg[id*2+1].val.re;
    if(seg[id*2].val.le==seg[id*2].r-seg[id*2].l+1) 
        seg[id].val.le=seg[id*2].val.le+seg[id*2+1].val.le;
    else 
        seg[id].val.le=seg[id*2].val.le;
}
void down(int id)
{
    if(seg[id].lazy==0) return;
    settag(id*2,seg[id].lazy);
    settag(id*2+1,seg[id].lazy);
    seg[id].lazy=0;
}
void build(int id, int l, int r)
{
    seg[id].l = l; seg[id].r = r;
    seg[id].val.l=l;seg[id].val.r=r;
    if(l == r)
    {
        seg[id].val.le=seg[id].val.re=1;
        return ; 
    }
    int mid = (l + r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid + 1, r);
    up(id);
}
void in(int id,int x,ll v)
{
    int l=seg[id].l,r=seg[id].r;
    if(l==r)
    {
        seg[id].val.re=seg[id].val.le=v;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid)
    {
        in(id*2,x,v);
    }
    else if(x>mid)
    {
        in(id*2+1,x,v);
    }
    up(id);
}
info sum(int id,int ql,int qr)
{
    int l=seg[id].l,r=seg[id].r;
    int ans;
    if(ql<=l&&r<=qr)
    {
        return seg[id].val;
    }
    int mid=(l+r)/2;
    if(qr<=mid)
    {
        return sum(id*2,ql,qr);
    }
    else if(ql>mid)
    {
        return sum(id*2+1,ql,qr);
    }
    else
    {
        return sum(id*2,ql,qr)+sum(id*2+1,ql,qr);
    }
}
int main()
{
    love;
    while(cin>>n>>q)
    {
        while(!d.empty())
        {
            d.pop();
        }
        build(1,1,n);
        while(q--)
        {
            cin>>ty;
            if(ty[0]=='D')
            {
                cin>>l;
                d.push(l);
                in(1,l,);
            }
            else if(ty[0]=='Q')
            {
                cin>>l;
                ll ans=0;
                ans+=sum(1,1,l).re;
                ans+=sum(1,l,n).le;
                if(ans) ans--;
                cout<<ans<<endl;
            }
            else if(ty[0]=='R')
            {
                if(!d.empty())
                {
                    l=d.top();
                    d.pop();
                    in(1,l,1);
                }
            }
        }
    }
}*/
int lowbit(int x)
{
    return x&(-x);
}
ll qpow(ll a,ll b,ll q)
{
    ll ans=1;
    while(b)
	{
        if(b&1)
		{
            ans=ans*a%q;
        }
        a=a*a%q;
        b/=2;
    }
    return ans;
}