
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
int amt,n,arr[10],dp[1000005];

string f1(int x){
	ostringstream str1; 
    str1 << x;
    string s = str1.str(); 
    return s;
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//memset(dp,-1,sizeof(dp));
	cin>>amt;
	int x = amt;
	int i=0;
	while(amt){
		arr[i++] = amt%10;
		amt/=10;
	}
	n=i;
	//cout<<f(x);
	dp[0] = 0;
	for (int i = 1; i <1000001; ++i)
	{
		dp[i] = 9999999;
	}
	for (int i = 1; i <= x; ++i)
	{
		string s = f1(i);
		for(int j=0;j<s.length();j++){
			if(i-(s[j]-'0')>=0) dp[i] = min(dp[i],1+dp[i-(s[j]-'0')]);
		}
	}
	cout<<dp[x];
	return 0;
}
