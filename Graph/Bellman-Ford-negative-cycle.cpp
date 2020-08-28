//Check negative cycle with bellman ford in O(n*m)
#include<bits/stdc++.h>
using namespace std;
struct edge{
	int source,dest,cost;
};
int n,r,p;
vector<edge> edges;
const int INF=1e9;
bool bellman()
{
	vector<int> dist(n+1);
	bool checkrelax=false;
	for(int i=0;i<n;i++)
	{
		checkrelax=false;
		for(int i=0;i<r;i++)
		{
			if(dist[edges[i].source]<INF && dist[edges[i].dest]>dist[edges[i].source]+edges[i].cost)
			{
				dist[edges[i].dest]=dist[edges[i].source]+edges[i].cost;
				checkrelax=true;
			}
		}
	}
	return checkrelax;
}
void solve()
{
    printf("Number of nodes and edges:\n");
	scanf("%d %d",&n,&r);
	edges.clear();
    printf("Enter the edges: \n");
	for(int i=1;i<=r;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		edge obj;
		obj.source=a,obj.dest=b,obj.cost=c;
		edges.emplace_back(obj);
	}
	bool ans=bellman();
	if(ans) printf("YES\n");
	else	printf("NO\n");
}
int main()
{
	int t;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		solve();
	}
    return 0;
}

