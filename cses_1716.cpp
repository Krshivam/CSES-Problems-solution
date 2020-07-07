
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

ll fact[2000005],inv[2000005];

ll f(ll a,ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = (ans*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return (ans+mod)%mod;
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fact[0] = 1;
	inv[0] = 1;
	for (ll i = 1; i <2000005; ++i)
	{
		fact[i] = (i*fact[i-1])%mod;
		inv[i] = f(fact[i],mod-2);
	}
	int n,m;
	cin>>n>>m;
	ll ans = ((fact[n+m-1]*inv[n-1])%mod*inv[m])%mod;
	cout<<ans;
	return 0;
}
