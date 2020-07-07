
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

ll arr[200005],lazy[1000000],tree[1000000];
int n,q;

void build(int l,int r,int node){
	if(l==r) {
		tree[node] = arr[l];
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,node<<1|1);
	tree[node] = tree[node<<1] + tree[node<<1|1];
}


void update(int l,int r,int node,int ql,int qr,ll val){
	if(lazy[node]){
		tree[node] += ((ll)(r-l+1))*1LL*lazy[node];
		if(l!=r){
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(ql>r || qr<l) return ;
	if(ql<=l && qr>=r) {
		tree[node] += ((ll)(r-l+1))*1LL*val;
		if(l!=r){
			lazy[node<<1] += val;
			lazy[node<<1|1] += val;
		}
		return ;
	}
	int mid = (l+r)>>1;
	update(l,mid,node<<1,ql,qr,val);
	update(mid+1,r,node<<1|1,ql,qr,val);
	tree[node] = tree[node<<1] + tree[node<<1|1];
}

ll query(int l,int r,int ql,int qr,int node){
	if(lazy[node]){
		tree[node] += ((ll)(r-l+1))*1LL*lazy[node];
		if(l!=r){
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(ql>r || qr<l) return 0LL;
	if(ql<=l && qr>=r) return tree[node];
	int mid = (l+r)>>1;
	return query(l,mid,ql,qr,node<<1)+query(mid+1,r,ql,qr,node<<1|1);

}



int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	build(0,n-1,1);
	while(q--){
		int id;
		cin>>id;
		if(id==1){
			int a,b;
			ll u;
			cin>>a>>b>>u;
			a--,b--;
			update(0,n-1,1,a,b,u);
		}
		else{
			int idx;
			cin>>idx;
			idx--;
			cout<<query(0,n-1,idx,idx,1)<<endl;
		}
	}
	return 0;
}
