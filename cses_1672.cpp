
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
vector<pll>adjlist[100005];
ll dist[501][501];
int visited[100005];


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>n>>m>>q;
	ll u,v,w;
	for (int i = 1; i <=n; ++i)
	{
		for(int j = 1; j<=n; j++) {
			dist[i][j] = 1e18;
			if(i==j) dist[i][j] = 0;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v>>w;
		dist[u][v] = min(dist[u][v],w);
		dist[v][u] = min(dist[u][v],w);
	}
	

	for (int i = 1; i <=n; ++i)
	{
		for(int j=1;j<=n;j++) {
				for(int k=1;k<=n;k++){
						dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
					}
				}
	}
	//int q;
	//cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<(dist[u][v]>=1e18 ? -1:dist[u][v])<<endl;
	}
	return 0;
}
