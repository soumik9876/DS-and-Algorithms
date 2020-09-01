//Count the number of articulation points in O(n+m)
#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > graph;
vector<int> visittime;
vector<int> low;
int timer=0,ans=0;
bool visited[10010];
bool iscutpoint[10010];
void dfs(int node,int p=-1)
{
	visited[node]=true;
	visittime[node]=low[node]=timer++;
	int childs=0;
	for(auto x: graph[node])
	{
		if(x==p) continue;
		if(visited[x])
		{
			low[node]=min(low[node],visittime[x]);
		}
		else
		{
			dfs(x,node);
			low[node]=min(low[node],low[x]);
			if(p!=-1 && visittime[node]<=low[x] && !iscutpoint[node])
			{
				iscutpoint[node]=true;
				ans++;
			}
			childs++;
		}
	}
	if(p==-1 && childs>1 && !iscutpoint[node])
	{
		iscutpoint[node]=true;
		ans++;
	}
}
void solve()
{
	int n,m;
    cout<<"How many nodes and edges?"<<endl;
	cin>>n>>m;
	graph=vector<vector<int> > (n+1);
	visittime=vector<int> (n+1,-1);
	memset(visited,false,sizeof(visited));
	memset(iscutpoint,false,sizeof(iscutpoint));
	low=vector<int>(n+1,-1);
    cout<<"Enter edges:"<<endl;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	timer=0,ans=0;
	dfs(1);
	cout<<"Number of articulation points "<<ans<<endl;
}
int main()
{
	int t;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		cout<<"Case "<<cn<<": ";
		solve();
	}
    return 0;
}

