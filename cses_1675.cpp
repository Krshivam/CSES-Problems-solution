
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
std::vector<pll>adjlist[100005];
pq1 q;

void prims(int u){
	visited[u] = 1;
	for (int i = 0; i < adjlist[u].size(); ++i)
	{
		if(!visited[adjlist[u][i].f]) q.push(mp(adjlist[u][i].s,adjlist[u][i].f));
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	ll u,v,c;
	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v>>c;
		adjlist[u].pb(mp(v,c));
		adjlist[v].pb(mp(u,c));
	}
	ll cost = 0;
	q.push(mp(0,1));
	while(!q.empty()){
		ll ct = q.top().f;
		int node = q.top().s;
		q.pop();
		if(!visited[node]) {
			cost+=ct;
			prims(node);
		}
	}
	for (int i = 1; i <=n; ++i)
	{
		if(!visited[i]){
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
	cout<<cost;
	return 0;
}
