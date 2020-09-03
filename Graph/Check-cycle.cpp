//Checking if a directed graph is cyclic in O(m)
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int> > graph;
vector<int> visited;
bool dfs(int node)
{
	visited[node]=1;
	for(auto x: graph[node])
	{
		if(visited[x]==0)
		{
			if(dfs(x))
				return true;
		}
		else if(visited[x]==1)
			return true;
	}
	visited[node]=2;
	return false;
}
void solve()
{
    cout<<"Enter the number of nodes and edges: "<<endl;
	cin>>n>>m;
	graph=vector<vector<int> > (n+1);
	visited=vector<int> (n+1);
	int cnt=0;
    cout<<"Enter the edges: "<<endl;
	for(int i=0;i<m;i++)
	{
		int s,t;
		cin>>s>>t;
		graph[s].emplace_back(t);
	}
	for(int i=0;i<=n;i++)
	{
		if(!visited[i])
		{
			if(dfs(i))
			{
				cout<<"Cycle exists"<<endl;
				return;
			}
		}
	}
	cout<<"No cycle"<<endl;
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

