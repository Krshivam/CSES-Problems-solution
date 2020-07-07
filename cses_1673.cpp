
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

std::vector<pll>adjlist[2501];
std::vector<int>adjlist1[2501];
ll dist[2501];
int visited[5000],visited1[5000];

void dfs(int u){
	visited[u] = 1;
	for (int i = 0; i < adjlist[u].size(); ++i)
	{
		if(!visited[adjlist[u][i].f]){
			dfs(adjlist[u][i].f);
		}
	}
}
void dfs1(int u){
	visited1[u] = 1;
	for (int i = 0; i < adjlist1[u].size(); ++i)
	{
		if(!visited1[adjlist1[u][i]]){
			dfs(adjlist1[u][i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int u,v;
	ll w;
	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v>>w;
		u--,v--;
		adjlist[u].pb(mp(v,w));
		//adjlist[v].pb(mp(u,w));
		adjlist1[v].pb(u);
	}
	for (int i = 0; i < n; ++i)
	{
		dist[i] = -1e18;
	}
	dist[0] = 0;
	dfs(0);
	dfs1(n-1);
	for (int i = 0; i < n-1; ++i)
	{
		for(int j=0;j<n;j++){
			for (int k = 0; k < adjlist[j].size(); ++k)
			{
				dist[adjlist[j][k].f] = max(dist[adjlist[j][k].f],dist[j]+adjlist[j][k].s);
			}
		}
	}
	bool flg=0;
	for(int j=0;j<n;j++){
		//cout<<dist[j]<<" ";
		for (int k = 0; k < adjlist[j].size(); ++k)
		{
			if(dist[adjlist[j][k].f]<dist[j]+adjlist[j][k].s && visited1[adjlist[j][k].f] && visited[adjlist[j][k].f]) {
				cout<<-1;
				return 0;
			}
		}
	}
	cout<<dist[n-1];
	return 0;
}
