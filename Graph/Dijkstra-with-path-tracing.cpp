//Dijkstra with path tracing O(n2+m)
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,r,source,dest;
vector<vector< pair<int,int> > > graph;
vector<int> previous;
int dijkstra()
{
	bool marked[n+1]={};
	vector<int> d(n+1,INF);
    previous.assign(n+1,-1);
	d[source]=0;
	for(int i=1;i<=n;i++)
	{
		int vertice=-1;
		for(int j=1;j<=n;j++)
		{
			if(!marked[j]  )
			{
				if(vertice==-1)
					vertice=j;
				else if(d[j]<d[vertice])
					vertice=j;
			}
		}
		if(d[vertice]==INF)
			break;
		marked[vertice]=true;
		for(auto x: graph[vertice])
		{
			if(d[x.first]>d[vertice]+x.second)
			{
				d[x.first]=d[vertice]+x.second;
                previous[x.first]=vertice;
			}
		}
	}
	return d[dest];
}
void pathprint()
{
    vector<int> path;
    int node=dest;
    while(node!=-1)
    {
        path.emplace_back(node);
        node=previous[node];
    }
    int sz=path.size();
    for(int i=sz-1;i>0;i--)
        printf("%d %d\n",path[i],path[i-1]);
}
void solve()
{
	scanf("%d %d %d %d",&n,&r,&source,&dest);
	graph.clear();
	graph=vector<vector < pair<int,int> > > (n+1);
	for (int i = 0; i < r; i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		graph[u].emplace_back(v,w);
		graph[v].emplace_back(u,w);
	}
	int ans=dijkstra();
    if(ans!=INF)
    {
        cout<<ans<<endl;
        pathprint();
    }
    else
        cout<<-1<<endl;
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

