
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

int dp[1000005];
int arr[105];
int n,amt;

int f(int val){
	if(val==0) return 0;
	if(dp[val]!=-1) return dp[val];
	int ans = 999999999;
	for (int i = 0; i < n; ++i)
	{
		if(val-arr[i]>=0){
			ans = min(ans,1+f(val-arr[i]));
		}
	}
	return dp[val]=ans;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp,-1,sizeof(dp));
	cin>>n>>amt;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int ans = f(amt);
	if(ans == 999999999) cout<<-1;
	else cout<<ans;
	return 0;
}
