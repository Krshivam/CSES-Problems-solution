
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
map<ll,int>m;
int n;
ll prefix[200005];

ll f(ll x){
	ll t=1;
	while(x<0){
		x+=(t*n);
		t*=2;
	}
	return x;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll d;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>d;
		prefix[i] = d;
		if(i) prefix[i] += prefix[i-1];
	}
	ll ans = 0;
	m[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		ll x = prefix[i];
		if(prefix[i]<0) x=f(x);
		ans += m[x%n];
		m[x%n]++;
	}
	cout<<ans;
	return 0;
}
