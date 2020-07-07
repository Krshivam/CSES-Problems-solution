
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

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n,m;
int visited[1002][1002];
ll dist[1002][1002];
char grid[1002][1002];
pair<pii,char>par[1002][1002];
std::map<int,char>dir;

// void dfs(int x,int y){
// 	vis[x][y] = 1;
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		int x1 = x+dx[i];
// 		int y1 = y+dy[i];
// 		if(x1>=0 && x1<n && y1>=0 && y1<m && dist[x1][y1]>1+dist[x][y] && (grid[x1][y1]=='.' || grid[x1][y1]=='B')){
// 			par[x1][y1] = mp(mp(x,y),dir[i]);
// 			dist[x1][y1] = 1+dist[x][y];
// 			dfs(x1,y1);
// 		}
// 	}
// }

void bfs(int x,int y){
	dist[x][y] = 0;
	queue<pii>q;
	q.push(mp(x,y));
	visited[x][y]=1;
	while(!q.empty()){
		pii node = q.front();
		q.pop();
		//cout<<"hello"<<endl;
		for (int i = 0; i < 4; ++i)
		{
			int x1 = node.first+dx[i];
			int y1 = node.second+dy[i];
			if(x1>=0 && x1<n && y1>=0 && y1<m && !visited[x1][y1] && (grid[x1][y1]=='.' || grid[x1][y1]=='B')){
				par[x1][y1] = mp(mp(node.first,node.second),dir[i]);
				dist[x1][y1] = 1+dist[node.first][node.second];
				visited[x1][y1] = 1;
				q.push(mp(x1,y1));
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	dir[0] = 'U';
	dir[1] = 'D';
	dir[2] = 'L';
	dir[3] = 'R';
	cin>>n>>m;
	int sx,sy,ex,ey;
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<m;j++) {
			cin>>grid[i][j];
			if(grid[i][j]=='A') sx=i,sy=j;
			if(grid[i][j]=='B') ex=i,ey=j;
			dist[i][j] = mod;
			visited[i][j]=0;
		}
	}
	bfs(sx,sy);

	if(visited[ex][ey]) {
		cout<<"YES\n";
		cout<<dist[ex][ey]<<endl;
		string s = "";
		int val = dist[ex][ey];
		int cnt=0;
		while(cnt<val) {
			s += par[ex][ey].second;
			int x = par[ex][ey].first.first;
			int y = par[ex][ey].first.second;
			ex = x;
			ey = y;
			cnt++;
		}
		reverse(s.begin(),s.end());
		cout<<s;
	}
	else cout<<"NO\n";
	return 0;
}
