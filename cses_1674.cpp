
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

int dp[200005];
std::map<int, std::vector<int> >adjlist;


int f(int u,int v){
	for (int i = 0; i < adjlist[u].size(); ++i)
	{
		if(adjlist[u][i]!=v){
			int x = f(adjlist[u][i],u);
			dp[u] += x;
		}
	}
	dp[u]+=1;
	return dp[u];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int u;
	for (int i = 2; i <=n; ++i)
	{
		cin>>u;
		adjlist[u].pb(i);
		adjlist[i].pb(u);
	}
	f(1,0);
	for (int i = 1; i <=n; ++i)
	{
		cout<<dp[i]-1<<" ";
	}
	return 0;
}
