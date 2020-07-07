
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

int n,m,visited[100005];
std::map<int, std::vector<int> >adjlist;

void dfs(int u){
	visited[u] = 1;
	for (int i = 0; i < adjlist[u].size(); ++i)
	{
		if(!visited[adjlist[u][i]]){
			dfs(adjlist[u][i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int u,v;
	std::vector<int>path;
	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v;
		adjlist[u].pb(v);
		adjlist[v].pb(u);
	}
	int ans=0;
	for (int i = 1; i <=n; ++i)
	{
		if(!visited[i]) {
			path.pb(i);
			dfs(i);
			ans++;
		}
	}
	if(ans==1) cout<<0;
	else{
		cout<<ans-1<<endl;
		for (int i = 0; i < ans-1; ++i)
		{
			cout<<path[i]<<" "<<path[i+1]<<endl;
		}
	}
	return 0;
}
