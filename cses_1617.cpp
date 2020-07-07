
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

ll f(ll n){
	ll ans = 1;
	ll a = 2;
	while(n) {
		ans = (ans*a)%mod;
		a = (a*a)%mod;
		n>>=1;
	}
	return (ans+mod)%mod;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	ll ans = 1;
	ll a = 2;
	for (int i = 0; i < n; ++i)
	{
		ans = (ans*a);
		ans%=mod;
		if(ans<0) ans+=mod;
	}
	cout<<ans;
	return 0;
}
