
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

int n,m,visited[100001],color[100001];
std::map<int,std::vector<int> >adjlist;
int b=0;

void dfs(int u,int c){
	visited[u] = 1;
	color[u] = c;
	for (int i = 0; i < adjlist[u].size(); ++i)
	{
		if(!visited[adjlist[u][i]]){
			dfs(adjlist[u][i],c^1);
		}
		else if(visited[adjlist[u][i]] && color[u]==color[adjlist[u][i]]) b=1;
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
		adjlist[v].pb(u);
	}
	for (int i = 1; i <=n ; ++i)
	{
		if(!visited[i]){
			dfs(i,0);
		}
	}
	if(b) cout<<"IMPOSSIBLE\n";
	else{
		for (int i = 1; i <=n; ++i)
		{
			if(color[i]==0) cout<<1<<" ";
			else cout<<2<<" ";
		}
	}
	return 0;
}
