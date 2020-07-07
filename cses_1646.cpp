
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

ll bit[200005];

int n,q;

void f(ll d,ll idx){
	while(idx<=n) {
		bit[idx] += d;
		idx += (idx&(-idx));
	}
}

ll get(int idx){
	ll sm = 0;
	while(idx>0) {
		sm += bit[idx];
		idx-= (idx&(-idx));
	}
	return sm;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	ll d;
	for (int i = 1; i <= n; ++i)
	{
		cin>>d;
		f(d,i);
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<get(r)-get(l-1)<<endl;
	}
	return 0;
}
