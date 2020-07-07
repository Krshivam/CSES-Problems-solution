
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll unsigned long long int
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

std::vector<std::vector<ll> >mat;
ll x = 6;

std::vector<std::vector<ll> >f1(std::vector<std::vector<ll> >a,std::vector<std::vector<ll> >b){
	std::vector<std::vector<ll> >c;
	c.resize(x);
	for (ll i = 0; i < x; ++i)
	{
		c[i].resize(x,0);
	}
	for (ll i = 0; i < x; ++i)
	{
		for(ll j=0;j<x;j++){
			for(ll k=0;k<x;k++){
				c[i][j] = (c[i][j]+a[i][k]*b[k][j])%mod;
				c[i][j] = (c[i][j]+mod)%mod;
			}
		}
	}
	return c;
}

std::vector<std::vector<ll> >f(std::vector<std::vector<ll> >a,ll p){
	if(p==1) return a;
	std::vector<std::vector<ll> >ans = f(a,p/2);
	if(p&1){
		return f1(a,f1(ans,ans));
	}
	return f1(ans,ans);
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mat.resize(x);
	for (ll i = 0; i < x; ++i)
	{
		mat[i].resize(x,0);
		for(ll j=0;j<x;j++){
			if(i==0) mat[i][j] = 1LL;
			if(j==i-1) mat[i][j] = 1LL;
		}
	}
	ll n;
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	n-=1;
	std::vector<std::vector<ll> >ans = f(mat,n);
	//cout<<ans[0].size();
	cout<<(ans[0][0]+ans[0][1])%mod;
	return 0;
}
