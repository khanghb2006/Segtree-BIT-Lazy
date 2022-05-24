#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<long,pair<long,long>>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_tuple

using namespace std;
const int N=1e5+7;
const int oo = 1e9 + 7;

struct data{
    int a,b,heigh;
};

data res[N];
int n,ans,dp[N],bit[N];

bool cmp(data u, data v)
{
    return mp(-u.b,u.a)<mp(-v.b,v.a);
}

void compress()
{
    vector<int>v;
    for(int i=1;i<=n;i++) v.pb(res[i].a);
    for(int i=1;i<=n;i++) v.pb(res[i].b);
    sort(all(v));
    for(int i=1;i<=n;i++)
        res[i].a=lower_bound(all(v),res[i].a)-v.begin()+1;
}

void update(int i,int val)
{
    for(; i<=n; i+=i&(-i)) bit[i] += val;
}

ll get(int pos)
{
    ll ans=0;
    for(; pos ;pos -= pos&(-pos)) ans+=bit[pos];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>res[i].a>>res[i].b>>res[i].heigh;
    for(int i=1;i<=n;i++){
        dp[i]=get(res[i].b-1)+res[i].heigh;
        update(res[i].a,dp[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
