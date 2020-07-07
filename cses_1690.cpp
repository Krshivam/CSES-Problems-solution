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

std::vector<int>adj[1001];

struct edge{
	int u,v,flow,cap;
};
std::vector<edge>graph;
int dist[10001],upto[10001];

int id=0,s,t,v,e;

bool bfs(){
	for (int i = 1; i <=v; ++i)
	{
		dist[i] = -1;
	}
	queue<int>q;
	dist[s] = 0;
	q.push(s);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = 0; i < adj[x].size(); ++i)
		{
			int curr = adj[x][i];
			int y = graph[curr].v;
			if(dist[y]==-1 && graph[curr].flow<graph[curr].cap){
				q.push(y);
				dist[y] = dist[x]+1;
			}
		}
	}
	return (dist[t]!=-1);
}

int dfs(int u,int val){
	if(val==0) return 0;
	if(u==t) return val;
	for(;upto[u]<adj[u].size();upto[u]++){
		int curr = adj[u][upto[u]];
		int x = graph[curr].v;
		//cout<<"Hello"<<endl;
		if(dist[x]!=dist[u]+1){
			//upto[x]++;
			continue;
		}
		int res = dfs(x,min(val,graph[curr].cap-graph[curr].flow));
		if(res>0){
			graph[curr].flow+=res;
			graph[curr^1].flow-=res;
			return res;
		}
		//upto[u]++;
	}
	return 0;
}

int dinic(){
	int flow=0;
	while(1){
		if(!bfs()) break;
		for (int i = 1; i <=v; ++i)
		{
			upto[i] = 0;
		}

		while(1){
			int currflow = dfs(s,11000);
			if(currflow==0) break;
			flow+=currflow;

		}
	}
	return flow;
}

void addEdge(int u,int v,int f){
	edge e,e1;
	e.u = u,e.v=v,e.flow=0;e.cap=f;
	e1.u = v,e1.v=u,e1.flow=0;e1.cap=0;
	adj[e.u].pb(id++);
	graph.pb(e);
	adj[e1.u].pb(id++);
	graph.pb(e1);
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	s=1,t=n;
	v=n,e=m;
	int u,v;
	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v;
		addEdge(u,v,1);
	}
    cout<<dinic();
	return 0;
}