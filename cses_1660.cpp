
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

ll n,x;
ll arr[200005];

int f(int i,int j,int k){
	if(i>j){
		return 0;
	}
	int mid = (i+j)>>1;
	if(arr[mid]-arr[k-1]==x){
		return 1;
	}
	else if(arr[mid]-arr[k-1]>x){
		return f(i,mid-1,k);
	}
	else return f(mid+1,j,k);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>x;
	for (int i = 1; i <= n; ++i)
	{
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	int k=1;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		cnt += f(1,n,i);
	}
	cout<<cnt;
	return 0;
}
