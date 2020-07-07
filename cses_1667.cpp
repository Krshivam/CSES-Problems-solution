
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

std::map<int,std::vector<int> >adjlist;
int visited[100005],dist[100005];

void bfs(int u){
	dist[u] = 1;
	visited[u] = 1;
	queue<int>q;
	q.push(u);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int i=0;i<adjlist[node].size();i++){
			if(!visited[adjlist[node][i]]){
				dist[adjlist[node][i]] = 1+dist[node];
				visited[adjlist[node][i]] = node;
				q.push(adjlist[node][i]);
			}
		}
	}
}

void f(int u){
	if(u==1) {
		cout<<1<<" ";
		return;
	}
	f(visited[u]);
	cout<<u<<" ";
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int u,v;
	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v;
		adjlist[u].pb(v);
		adjlist[v].pb(u);
	}
	bfs(1);
	if(visited[n]) {
		cout<<dist[n]<<endl;
		f(n);
	}
	else cout<<"IMPOSSIBLE";
	return 0;
}
