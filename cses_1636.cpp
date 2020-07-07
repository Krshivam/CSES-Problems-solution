
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
int n,amt,arr[101];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>amt;
	for (int i = 0; i <n; ++i)
	{
		cin>>arr[i];
	}
	dp[0] = 1;
	for(int i=0;i<n;i++){
		for(int j=arr[i];j<1000001;j++){
			dp[j] = (dp[j]+dp[j-arr[i]])%mod;
		}
	}
	cout<<dp[amt];
	return 0;
}
