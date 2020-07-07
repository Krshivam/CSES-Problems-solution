
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
std::map<int, std::vector<int> >adjList;
int parent[100005],flag = 0;
int node;

void dfs(int u,int v) {
	parent[u] = v;
	for (int i = 0; i < adjList[u].size(); ++i)
	{
		if(!parent[adjList[u][i]]) {
			dfs(adjList[u][i],u);
		}
		else if(parent[adjList[u][i]] && parent[adjList[u][i]]!=v) {
			flag = 1;
			parent[adjList[u][i]] = v;
			node = adjList[u][i];
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
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	dfs(1,1);
	if(flag) {
		cout<<node<<endl;
	}
	return 0;
}
