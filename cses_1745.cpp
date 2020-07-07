
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

int n,arr[101];
int dp[101][100001];

set<int>s;

int f(int i,int amt){
	if(i==n){
		if(amt>0) s.insert(amt);
		return 0;
	}
	if(dp[i][amt]!=-1) return dp[i][amt];
	int ans;
	ans = f(i+1,amt+arr[i]);
	ans = f(i+1,amt);
	return dp[i][amt] = ans;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	reset(dp,-1);
	int ans = f(0,0);
	cout<<s.size()<<endl;
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		cout<<(*it)<<" ";
	}
	return 0;
}
