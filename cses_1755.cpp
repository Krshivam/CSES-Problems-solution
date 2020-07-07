
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
#define pq priority_queue<int,vector<int>,greater<int> >
#define pq1 priority_queue<pll,vector<pll>,greater<pll> >

const int mod = 1e9+7;

std::map<char, int> m;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int n = s.length();
	sort(s.begin(),s.end());
	string s1="",s2="",s3="";
	for (int i = 0; i < n; )
	{
		if(i+1<n && s[i]==s[i+1]) s1+=s[i],s2+=s[i],i+=2;
		else s3+=s[i],i++;
	}
	if(s3.size()>1) cout<<"NO SOLUTION";
	else{
		reverse(s2.begin(),s2.end());
		cout<<s1<<s3<<s2;
	}
	return 0;
}
