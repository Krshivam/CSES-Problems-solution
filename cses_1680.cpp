
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

int n,m;
std::vector<int> adjlist[100005];
int deg[100005],dp[100005],parent[100005],visited[100005];
stack<int>s;
vector<int>vec;

void dfs(int u){
	visited[u] = 1;
	for (int i = 0; i < adjlist[u].size(); ++i)
	{
		if(!visited[adjlist[u][i]]) {
			dfs(adjlist[u][i]);
		}
	}
}

void topsort(){
	
	for (int i = 1; i <=n; ++i)
	{
		if(deg[i]==0) s.push(i);
	}
	while(s.size()) {
		int node = s.top();
		s.pop();
		vec.pb(node);
		for (int i = 0; i < adjlist[node].size(); ++i)
		{
			deg[adjlist[node][i]]--;
			if(deg[adjlist[node][i]]==0) s.push(adjlist[node][i]);
		}
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
		deg[v]++;
	}
	dfs(1);
	if(!visited[n]){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	topsort();
	memset(dp,-mod,sizeof(dp));
	for (int i = vec.size()-1; i>=0; i--)
	{
		if(vec[i]==n) dp[vec[i]] = 1;

		for(int j=0;j<adjlist[vec[i]].size();j++){
			if(dp[vec[i]]<dp[adjlist[vec[i]][j]]+1) {
				dp[vec[i]] = dp[adjlist[vec[i]][j]]+1;
				parent[vec[i]] = adjlist[vec[i]][j];
			}
		}
		//cout<<vec[i]<<" "<<dp[vec[i]]<<endl;
	}

	cout<<dp[1]<<endl;
	int node = 1;
	while(node!=n) {
		cout<<node<<" ";
		node = parent[node];
	}
	cout<<n;
	return 0;
}
