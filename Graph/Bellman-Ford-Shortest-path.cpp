//Single source shortest path for negative edge graphs with bellman ford algorithm in O(n*m)
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,m,q;
vector<vector<pair<int,int>>> graph;
void bellman(vector<int> &dist)
{
	for(int i=2;i<=n;i++)
		dist[i]=INF;
	dist[1]=0;
	for(int i=1;i<n;i++)
	{
		bool checkrelax=false;
		for(int i=1;i<=n;i++)
		{
			for(auto x: graph[i])
			{
				if(dist[i]<INF && dist[x.first]>dist[i]+x.second)
				{
					dist[x.first]=dist[i]+x.second;
					checkrelax=true;
				}
			}
		}
		if(!checkrelax)
			break;
	}
}
void solve()
{
    cout<<"Number of nodes and edges:"<<endl;
	cin>>n>>m;
	graph=vector<vector<pair<int,int>>> (n+1);
    cout<<"Enter the edges"<<endl;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].emplace_back(v,w);
	}
	vector<int> dist(n+1);
	bellman(dist);
    cout<<"How many queries: "<<endl;
	cin>>q;
    cout<<"Shortest distance from 1 to which node?"<<endl;
	while(q--)
	{
		int node;
		cin>>node;
		if(dist[node]!=INF)
			cout<<dist[node]<<endl;
		else
			cout<<"Unreachable"<<endl;
	}
}
int main()
{
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		cout<<"Case "<<cn<<":"<<endl;
		solve();
	}
    return 0;
}

