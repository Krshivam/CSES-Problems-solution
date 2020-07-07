
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
vector<pll>adjlist[100005],adjlist1[100005];
ll dist[100005],distb[100005];
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
void dijkstra1(int src) {
	distb[src] = 0;
	pq1 q;
	q.push(mp(distb[src],src));
	while(!q.empty()) {
		pii node = q.top();
		q.pop();
		if(visited[node.s]) continue;
		visited[node.s] = 1;
		for(int i=0;i<adjlist1[node.second].size();i++) {
			if(distb[adjlist1[node.s][i].f]>distb[node.s]+adjlist1[node.s][i].s) {
				distb[adjlist1[node.s][i].f]=distb[node.s]+adjlist1[node.s][i].s;
				q.push(mp(distb[adjlist1[node.s][i].f],adjlist1[node.s][i].f));
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int n,m;
	cin>>n>>m;
	ll u,v,w;
	std::vector<pair<pll,ll> > edges;
	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v>>w;
		adjlist[u].pb(mp(v,w));
		adjlist1[v].pb(mp(u,w));
		dist[u] = 1e18;
		dist[v] = 1e18;
		distb[u] = 1e18;
		distb[v] = 1e18;
		edges.pb(mp(mp(u,v),w));
		//adjlist[v].pb(mp(u,w));
	}
	//parent[1] = -1;
	dijkstra(1);
	memset(visited,0,sizeof(visited));
	dijkstra1(n);
	ll mx = 1e18;
	for (int i = 0; i < edges.size(); ++i)
	{
		mx = min(mx,dist[edges[i].f.f]+distb[edges[i].f.s]+edges[i].s / 2);
	}
	cout<<mx;
	return 0;
}
