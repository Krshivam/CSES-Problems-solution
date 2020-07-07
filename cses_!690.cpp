
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

ll mat[21][21];
int n,m;
ll dp[21][(1<<20)+1];

ll f(int i,int mask) {
	if(i==n-1) {
		return (mask==(1<<n)-1);
	}
	if(dp[i][mask]!=-1) return dp[i][mask];
	ll ans = 0;
	//cout<<i<<" ";
	for(int j=1;j<n;j++) {
		if((mask&(1<<j))==0 && mat[i][j]){
			
			ans = (ans+mat[i][j]*f(j,mask|(1<<j)))%mod;
		}
	}
	return dp[i][mask] = ans;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int u,v;
	memset(mat,0,sizeof(mat));
	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v;
		u--,v--;
		mat[u][v] += 1;
		//mat[v][u] = 1;
	}
	memset(dp,-1,sizeof(dp));
	cout<<f(0,1);
	return 0;
}
