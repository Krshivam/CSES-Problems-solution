
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long
#define pb push_back
#define mp make_pair
#define inp(x) cin>>x
#define print(x) cout<<x
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)
#define reset(d,val) memset(d,val,sizeof(d))
#define sort(v) sort(v.begin(),v.end())
#define sort_arr(arr,i,f) sort(arr+i,arr+f)
#define pq priority_queue<int,vector<int>,greater<int> >
#define pq1 priority_queue<pll,vector<pll>,greater<pll> >

const int mod = 1e9+7;

std::vector<int>adjlist[100005];
ll dp[100005],vis[100005];
int n,m;

void dfs(int u){
	vis[u] = 1;
	if(u==n) dp[u] = 1;
	for (int i = 0; i < adjlist[u].size(); ++i)
	{
		if(!vis[adjlist[u][i]]){
			dfs(adjlist[u][i]);
		}
		dp[u] += dp[adjlist[u][i]];
		if(dp[u]>=mod) dp[u]-=mod;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	int u,v;
	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v;
		adjlist[u].pb(v);
	}
	for (int i =1; i <=n; ++i)
	{
		if(!vis[i]){
			dfs(i);
		}
	}
	cout<<dp[1];
	return 0;
}
