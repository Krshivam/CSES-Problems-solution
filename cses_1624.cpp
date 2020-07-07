
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

char grid[8][8];

bool ispossible(int i,int k) {

	//cout<<"Hell";
	if(grid[i][k]=='*') return 0;
	for (int j = 0; j < 8; ++j)
	{
		if(grid[i][j]=='q') return 0;
		if(grid[j][k]=='q') return 0;
	}
	int  x=i,y=k;
	while(x>=0 && y>=0) {
		if(grid[x][y]=='q') return 0;
		x--,y--;
	}
	x = i,y = k;
	while(x>=0 && y<8) {
		if(grid[x][y]=='q') return 0;
		x--,y++;
	}
	
	return 1;

}

ll ans = 0;
bool f(int i) {
	if(i==8) {
		//cout<<"Hello";
		ans += 1;
		return 0;
	}
	//if(j==8) return f(i+1,0);
	//ll ans = 0;
	for(int k=0;k<8;k++) {
		//cout<<"Hello\n";
		if(ispossible(i,k)) {
			grid[i][k] = 'q';
			if(f(i+1)) return 1;
			else {
				grid[i][k] = '.';
			}
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cin>>grid[i][j];
		}
	}
	bool val = f(0);
	cout<<ans;
	return 0;
}
