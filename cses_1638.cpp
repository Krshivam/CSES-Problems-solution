
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

int n;
char grid[1000][1000];
ll dp[1001][1001];

ll f(int i,int j){
	if(grid[i][j]=='*') return 0;
	if((i==n && j==n-1) || (i==n-1 && j==n)) return grid[i][j]!='*';
	if(i==n || j==n) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	ll ans = 0;
	ans = (ans+f(i+1,j))%mod;
	ans = (ans+f(i,j+1))%mod;
	return dp[i][j] = (ans+mod)%mod;
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<n;j++) cin>>grid[i][j];
	}
	dp[0][0] = (grid[0][0]=='.');
	for (int i = 1; i < n; ++i)
	{
		dp[0][i] = (grid[0][i]=='.' && dp[0][i-1]);
		dp[i][0] = (grid[i][0]=='.' && dp[i-1][0]);
	}
	for (int i = 1; i <n; ++i)
	{
		for(int j=1;j<n;j++){
			if(grid[i][j]=='.') dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
			else dp[i][j] = 0;
		}
	}
	cout<<(dp[n-1][n-1]+mod)%mod;
	return 0;
}
