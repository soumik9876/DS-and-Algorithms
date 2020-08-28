//Single source shortest path in O(nlogn+m) complexity
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,m,s,t,p;
void dijkstra(vector<vector< pair<int,int> > > &g,vector<int> &dist)
{
	 for(int i=1;i<=n;i++)
	 	dist[i]=INF;
	dist[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		int node=pq.top().second;
		int dis=pq.top().first;
		pq.pop();
		if(dist[node]!=dis)
			continue;
		for(auto x: g[node])
		{
			if(dist[x.first]>dis+x.second)
			{
				dist[x.first]=dis+x.second;
				pq.push(make_pair(dis+x.second,x.first));
			}
		}
	}
}
void solve()
{
    printf("Enter number of nodes,edges,source and destination\n");
	scanf("%d %d %d %d",&n,&m,&s,&t);
	vector<vector<pair<int,int>> > graph(n+1);
    printf("Enter the edges:\n");
	for(int i=0;i<m;i++)
	{
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		graph[u].emplace_back(v,c);
	}
	vector<int> dist1(n+1);
	dijkstra(graph,dist1);
    if(dist1[t]!=INF)
	    printf("%d\n",dist1[t]);
    else
        printf("Unreachable\n");
}	
int main()
{
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		printf("Case %d: ",cn);
		solve();
	}
    return 0;
}

