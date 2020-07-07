
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

ll dp[501][125001];
int n,total;

ll f(int i,int sm){
	if(i==n+1) return (2*sm)==total;
	if(dp[i][sm]!=-1) return dp[i][sm];
	ll ans = 0;
	ans = (ans+f(i+1,sm+i))%mod;
	ans = (ans+f(i+1,sm))%mod;
	return dp[i][sm] = (ans+mod)%mod;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	total = (n*(n+1))/2;
	//cout<<total<<endl;
	if(total%2) {
		cout<<0;
		return 0;
	}
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=total;j++){
			if(j-i>=0){
				dp[i][j] = (dp[i-1][j] + dp[i-1][j-i])%mod;
			}
			else dp[i][j] = dp[i-1][j];
		}
	}

	cout<<dp[n][total/2];
	return 0;
}
