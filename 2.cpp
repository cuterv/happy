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
#define all(a) a.begin(),a.end()
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e6+10;
const double pi = acos(-1.0);
ll Exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = Exgcd(b, a % b, x, y);
  ll t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
int main()
{
	ll x, y, m, n, L, X, Y, d, r;
    //(x+k*m-y-k*n)%l==0;
	cin >> x >> y >> m >> n >> L;
	d = Exgcd(n - m, L, X, Y); r = L / d;
	if ((x - y) % d) cout << "Impossible" << endl;
	else cout << ((x - y) / d * X % r + r) % r << endl;
	return 0;
}