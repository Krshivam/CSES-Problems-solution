
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

ll dp[1000005];
int tot;

ll f(int sm){
	if (sm==tot) return 1;
	if(dp[sm]!=-1) return dp[sm];
	ll ans = 0;
	for(int i=1;i<=6;i++){
		if(i+sm<=tot){
			ans = (ans + f(i+sm))%mod;
		}
	}
	return dp[sm] = ans%mod;
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	reset(dp,-1);
	cin>>tot;
	cout<<f(0);
	return 0;
}
