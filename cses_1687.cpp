
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

int dp[200005][20];
int height[200005],parent[200005];
std::map<int, std::vector<int> >adjlist;

void dfs(int u,int v,int h){
	
	for (int i = 0; i < adjlist[u].size(); ++i)
	{
		if(adjlist[u][i]!=v){
			dfs(adjlist[u][i],u,h+1);
		}
	}
	height[u] = h;
	parent[u] = v;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 200005; ++i)
	{
		for(int j=0;j<20;j++){
			dp[i][j] = -1;
		}
	}
	
	int u,n,q;
	cin>>n>>q;
	for (int i = 2; i <=n; ++i)
	{
		cin>>u;
		adjlist[u].pb(i);
		adjlist[i].pb(u);
	}
	dfs(1,-1,0);
	for(int i=1;i<=n;i++){
		dp[i][0] = parent[i];
	}
	for (int i = 1; i <20; ++i)
	{
		for(int j=1;j<=n;j++){
			if(dp[j][i-1]!=-1){
				dp[j][i] = dp[dp[j][i-1]][i-1];
			}
		}
	}
	while(q--){
		int k;
		cin>>u>>k;
		int log=0;
		while((1<<log)<=k){
			log++;
		}
		log--;
		for(int i=log;i>=0;i--){
			if(k-(1<<i)>=0){
				u = dp[u][i];
				if(u==-1) break;
				k-=(1<<i);
			}
		}
		cout<<u<<endl;
	}
	return 0;
}
