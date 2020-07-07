
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
pii dp[200005];
map<int,std::vector<int> >adjlist;
int ans = 0;

void f(int u,int v){
	int mx = 0;
	int smax = 0;
	for(int i=0;i<adjlist[u].size();i++){
		if(adjlist[u][i]!=v){
			f(adjlist[u][i],u);
			if(dp[adjlist[u][i]].first+1>=mx){
				int temp = mx;
				mx = dp[adjlist[u][i]].first+1;
				smax = temp;
			}
			else if(dp[adjlist[u][i]].first+1>smax){
				smax = dp[adjlist[u][i]].first+1;
			}
		}
	}
	dp[u] = mp(mx,mx+smax);
	ans = max(ans,mx+smax);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int u,v;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>u>>v;
		adjlist[u].pb(v);
		adjlist[v].pb(u);
	}
	f(1,0);
	for (int i = 1; i <=n; ++i)
	{
		cout<<dp[i].first<<" "<<dp[i].second<<endl;
	}
	return 0;
}
