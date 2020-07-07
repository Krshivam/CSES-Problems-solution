
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

ll arr[21];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll mn = 1e12;
	ll tot=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		tot+=arr[i];
	}
	for (int i = 0; i < 1<<n; ++i)
	{
		ll sm = 0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)) {
				sm += arr[j];
			}
		}
		mn = min(mn,abs(tot-2*sm));
	}
	cout<<mn;
	return 0;
}
