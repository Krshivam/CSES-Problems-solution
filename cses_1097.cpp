
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
ll arr[5000],dp[5001][5001];

ll f(int i,int j){
	if(i>j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	ll ans = -99999999999;
	ans = max(ans,arr[i]+min(f(i+1,j-1),f(i+2,j)));
	ans = max(ans,arr[j]+min(f(i+1,j-1),f(i,j-2)));
	return dp[i][j] = ans;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	reset(dp,-1);
	cout<<f(0,n-1);
	return 0;
}
