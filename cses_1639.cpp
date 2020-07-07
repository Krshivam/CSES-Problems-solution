
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

string s1,s2;
int dp[5000][5000];
int n,m;

int f(int i,int j){
	if(i==n) return m-j;
	if(j==m) return n-i;
	if(i==n || j==m) return 99999999;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans=99999999;
	if(s1[i]==s2[j]){
		ans = min(ans,f(i+1,j+1));
	}
	else {
		ans = min(ans,1+f(i+1,j+1));
		ans = min(ans,1+f(i,j+1));
		ans = min(ans,1+f(i+1,j));
	}
	return dp[i][j]=ans;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp,-1,sizeof(dp));
	cin>>s1>>s2;
	n = s1.length();
	m = s2.length();
	memset(dp,-1,sizeof(dp));
	cout<<f(0,0);
	return 0;
}
