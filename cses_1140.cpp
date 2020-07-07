
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
#define pq priority_queue<int,vector<int>,greater<int> >
#define pq1 priority_queue<pll,vector<pll>,greater<pll> >

const int mod = 1e9+7;

int n;
pii arr[200005];
ll p[200005],dp[200005];

bool compare(pii a,pii b){
	return a.second<b.second;
}

ll f(int i){
	if(i==n) return 0;
	if(dp[i]!=-1) return dp[i];
	ll ans =0 ;
	ans = max(ans,p[i]+f(i+1));
	ans = max(ans,f(i+1));
	return dp[i] = ans;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i].first>>arr[i].second;
		cin>>p[i];
	}
	sort(arr,arr+n,compare);
	reset(dp,-1);
	cout<<f(0);
	return 0;
}
