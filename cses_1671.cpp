
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
#define pq1 priority_queue<pll,vector<pll>,greater<pl>l >

const int mod = 1e9+7;

int n,m;
vector<pll>adjlist[100005];
ll dist[100005];
int visited[100005];

void dijkstra(int src) {
	dist[src] = 0;
	pq1 q;
	q.push(mp(dist[src],src));
	while(!q.empty()) {
		pii node = q.top();
		q.pop();
		if(visited[node.s]) continue;
		visited[node.s] = 1;
		for(int i=0;i<adjlist[node.second].size();i++) {
			if(dist[adjlist[node.s][i].f]>dist[node.s]+adjlist[node.s][i].s) {
				dist[adjlist[node.s][i].f]=dist[node.s]+adjlist[node.s][i].s;
				q.push(mp(dist[adjlist[node.s][i].f],adjlist[node.s][i].f));
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	ll u,v,w;
	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v>>w;
		adjlist[u].pb(mp(v,w));
		//adjlist[v].pb(mp(u,w));
		dist[u] = 1000000000000000;
		dist[v] = 1000000000000000;
	}
	dijkstra(1);
	for (int i = 1; i <=n; ++i)
	{
		cout<<dist[i]<<" ";
	}
	return 0;
}
