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
const double PI=3.14159;
int main()
{
    love;
    double ans=20*1000,r,h,v,pp;
    cin>>h>>r;
    v=PI*r*r*h;
    cout<<ceil(ans/v)<<endl;
}