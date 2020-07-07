
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

int tree[1000000],arr[200005];

void build(int l,int r,int node){
	if(l==r){
		tree[node] = arr[l];
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,node<<1 | 1);
	tree[node] = min(tree[node<<1],tree[node<<1 | 1]);
}

int get(int l,int r,int ql,int qr,int node){
	if(ql<=l && qr>=r) return tree[node];
	if(ql>r || qr<l) return mod;
	int mid = (l+r)>>1;
	return min(get(l,mid,ql,qr,node<<1),get(mid+1,r,ql,qr,node<<1 | 1));
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	build(0,n-1,1);
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<get(0,n-1,l-1,r-1,1)<<endl;
	}
	
	return 0;
}
